#include <iostream>

using namespace std;

// const int N =1e6+10;

// int n,m;
// int q[N];


int main()
{
    double x;
    cin>>x;

    double l =-10000,r=10000;
    while(r-l>1e-8)
    {
        double mid = (l+r)/2;

        if(mid*mid*mid>=x){
            r =mid;
        }
        else{
            l=mid;
        }
    }
    printf("%lf\n",l);
    return 0;
}