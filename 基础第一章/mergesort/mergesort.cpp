#include <iostream>

using namespace std;

const int N =1e6+10;

int n;
int q[N],tmp[N];

void merge(int q[],int l,int r)
{
    if(l>=r)return;
    int mid =l+r>>1;
    merge(q,l,mid),merge(q,mid+1,r);
    int i=l,j=mid+1,k=0;
    while(i<=mid&&j<=r)
    {
        if(q[i]<=q[j])tmp[k++]=q[i++];
        else    tmp[k++]=q[j++];
    }
    while(i<=mid)tmp[k++]=q[i++];
    while(j<=r) tmp[k++]=q[j++];
    for(i=l,k=0;i<=r;i++,k++)q[i]=tmp[k];
}


int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&q[i]);
    
    merge(q,0,n-1);

    
    for(int i=0;i<n;i++)printf("%d",q[i]);
    return 0;
}