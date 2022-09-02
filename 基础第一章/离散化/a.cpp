/*
    值域很大，个数很少

    0~10e9 ,        个数10e5
                                      1   3   34   23434         342342                   
    映射到自然数                       0   1    2     3              4
    


     1、a[]中可能有重复元素   去重！！
     2.如何计算a[i]离散话后的值

离散化 —— 模板题 AcWing 802. 区间和
vector<int> alls; // 存储所有待离散化的值
sort(alls.begin(), alls.end()); // 将所有值排序
alls.erase(unique(alls.begin(), alls.end()), alls.end());
// 去掉重复元素

// 二分求出x对应的离散化的值
int find(int x) // 找到第一个大于等于x的位置
{
    int l = 0, r = alls.size() - 1;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (alls[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return r + 1; // 映射到1, 2, ...n
                不加     0,1,2....
}
*/ 
#include <iostream>
#include <vector>
#include <algorithm>



using namespace std;

using pii =pair<int,int>;

const int N=300010;

int n,m;
int a[N],s[N];
vector<int> alls;
vector<pii> add,query;

vector<int>::iterator unique(vector<int>& a)
{
    int j=0;
    for(int i=0;i<a.size();i++)
    {
        if(!i||a[i]!=a[i-1])
        {
            a[j++]=a[i];
        }
    }
    return a.begin()+j;
}

int find(int x)
{
    int l=0,r=alls.size()-1;
    while(l<r)
    {
        int mid =l+r>>1;
        if(alls[mid]<x)l=mid+1;
        else r=mid;
    }
    return r+1;     //映射到从1开始的自然数，方便做前缀和
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        int x,c;
        cin>>x>>c;
        add.push_back({x,c});
        alls.push_back(x);
    }

    for(int i=0;i<m;i++)
    {
        int l,r;
        cin>>l>>r;
        query.push_back({l,r});
        alls.push_back(l);
        alls.push_back(r);
    }


    //去重
    sort(alls.begin(),alls.end());
    alls.erase(unique(alls),alls.end());


    //处理插入
    for(auto item:add)
    {
        int x=find(item.first);
        a[x]+=item.second;
    }



    //预处理前缀和
    for(int i=1;i<=alls.size();i++){
        s[i] = s[i-1]+a[i];
    }

    //处理询问
    for(auto item:query)
    {
        int l =find(item.first),r=find(item.second);
        cout<<s[r]-s[l-1]<<endl;
    }
    return 0;
}





