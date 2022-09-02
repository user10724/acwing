#include <iostream>

using namespace std;

int main(){


    int n=10;
    for(int i=3;i>=0;i--)
    {
        cout<<(n>>i&1);
    }
}