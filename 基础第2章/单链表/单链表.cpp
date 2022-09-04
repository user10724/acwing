#include <iostream>

using namespace std;

const int N =100010;


//head 表示头节点的下标

//e[i]表示节点i的值
// ne[i]表示节点i的next指针；

//idx 存储当前已经用到了哪个点
int head,e[N],ne[N],idx;

//初始化

void init()
{
    head = -1;
    idx = 0;
}

void add_to_head(int x)
{   
    e[idx] =x;
    ne[idx]=head;
    head = idx;
    idx++;
}

void add(int k,int x)
{
    e[idx]=x;
    ne[idx] =ne[k];
    ne[k]=idx;
    idx++; 
}

void remove(int k)
{
    ne[k] = ne[ne[k]];
}

int main()
{
    int m;
    cin>>m;
    
    init();
    while(m--)
    {   
        int k,x;
        char op;

        cin>>op;
        if(op=='H')
        {
            cin>>x;
            add_to_head(x);
        }
        else if(op=='D')
        {
            cin>>k;
            if(!k)head =ne[head];
            remove(k-1);
        }
        else{
            cin>>k>>x;
            add(k-1,x);
        }
    }
    for (int i =head;i!=-1;i=ne[i])
    {
        cout<<e[i]<<' ';
    }
    cout<<endl;
    return 0;
}

/*
10
H 9
I 1 1
D 1
D 0
H 6
I 3 6
I 4 5
I 4 5
I 3 4
D 6
*/