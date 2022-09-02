//返回x的最后一位1

/*

    x=1010  =>  10;
    x=101000 =>1000


    (x&-x)  =>  x&(~x+1)      x 1010.....100000
                            ~x  0101.....011111
                          ~x+1  0101.....100000
                      x&(~x+1)  0000.....100000
    负数是补码
    -x =~x+1
*/

#include <iostream>

using namespace std;

int lowbit(int x)
{
    return x&-x;
}

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int x;
        cin>>x;

        int res = 0;

        while(x)    x-=lowbit(x),res++;

        cout<<res<<endl;
    }
}
