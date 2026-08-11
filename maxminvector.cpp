#include<iostream>
#include<vector>
using namespace std;

int maximum, minimum;

void maxmin(vector<int>& v, int l, int r)
{
    if(l==r)
    {
        if(v[l]>maximum)maximum = v[l];
        if(v[l]<minimum)minimum=v[l];
        return;
    }
    int mid =(l+r)/2;
    maxmin(v,l,mid);
    maxmin(v,mid+1,r);
}
int main()
{
    vector<int> v= {9, 6, 4, 7, 10, 14, 8, 11};
    int n= v.size();

    maximum=v[0];
    minimum=v[0];

    maxmin(v,0,n-1);
    cout<<maximum<<endl<<minimum;

}