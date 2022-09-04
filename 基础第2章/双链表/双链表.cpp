#include <iostream>

using namespace std;

const int N =100010;
int m;
int e[N],l[N],r[N],idx;

struct Node
{
    int e,l,r;
}nodes[N];

//初始化

void init()
{
    //0表示左端点，1表示右端点
    r[0]=1;
    l[1]=0;
    idx =2;
}

//在k的右边插入x
void add(int k,int x)
{
    e[idx] = x;
    r[idx] = r[k];
    l[idx]=k;
    l[r[k]]=idx;
    r[k] = idx;
}

void remove(int k)
{
    r[l[k]] = r[k];
    l[r[k]]=l[k];

    //nodes[nodes[k].l].r=nodes[k].r;
}
