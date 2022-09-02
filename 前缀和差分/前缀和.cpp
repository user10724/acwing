#include <iostream>

using namespace std;

const int N =1e6+10;

int n,m;
int a[N],s[N];



int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    
    s[0]=0;
    for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];

    while(m--)
    {
        int l,r;
        cin>>l>>r;
        cout<<s[r]-s[l-1];
    }
    return 0;
}