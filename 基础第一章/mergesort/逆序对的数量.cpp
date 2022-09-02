#include <iostream>

using namespace std;


using ll =long long;
const int N =1e6+10;

int n;
int q[N],tmp[N];

ll merge_sort(int l,int r)
{
    if(l>=r)return 0;
    int mid =l+r>>1;
    ll res =merge_sort(l,mid)+merge_sort(mid+1,r);
    int i=l,j=mid+1,k=0;
    while(i<=mid&&j<=r)
    {
        if(q[i]<=q[j])tmp[k++]=q[i++];
        else  {
            tmp[k++]=q[j++];
            res+=mid-i+1;
        }  
    }
    while(i<=mid)tmp[k++]=q[i++];
    while(j<=r) tmp[k++]=q[j++];
    for(i=l,k=0;i<=r;i++,k++)q[i]=tmp[k];

    return res;
}


int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>q[i];
    }
    cout<<merge_sort(0,n-1)<<endl;

}
