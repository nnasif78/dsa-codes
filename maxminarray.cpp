#include<iostream>
using namespace std;
int maximum;
int minimum;
void maxmin(int arr[],int l,int r)
{
    if(l==r)
    {
        if(arr[l]>maximum)maximum = arr[l];
        if (arr[l]<minimum)minimum = arr[l];
        return;
    }
    int mid =(l+r)/2;
    maxmin(arr, l, mid);
    maxmin(arr,mid+1,r);
}
int main ()
{
    int arr[]={9, 6, 4, 7, 10, 14, 8, 11};
    int n= sizeof(arr)/sizeof(arr[0]);
     maximum = arr[0];
     minimum = arr[0];

    maxmin(arr,0,n-1);
    cout<<maximum<<endl<<minimum;
    
}
