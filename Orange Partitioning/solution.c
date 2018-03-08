#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void partition (int a[],int low,int high)
{
    int pivot,i,j,n=high+1;
    // pivot (Element to be placed at right position)
    pivot = a[high];

    i = (low - 1);
    int temp;
    // Index of smaller element

    for (j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (a[j] <= pivot)
        {
            i++;    // increment index of smaller element
            temp=a[i];
                a[i]=a[j];
                a[j]=temp;
        }
    }

    temp=a[i+1];
    a[i+1]=a[high];
    a[high]=temp;
    for(i=0;i<n;i++){
        cout<<a[i]<<" ";
    }

}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,i,j,temp;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    partition(a,0,n-1);



    return 0;
}
