#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    int n,i,j,temp;
    cin>>n;
    int a[n];

    for(i=0;i<n;++i)
        cin>>a[i];

    for(i=1;i<n;++i)
    {
        for(j=0;j<(n-i);++j)
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
    }


    for(i=0;i<n;++i)
        cout<<a[i]<<" ";

    return 0;
}
