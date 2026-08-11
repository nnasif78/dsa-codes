#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int crossSum(vector<int> &v, int l, int mid, int r,int & s, int & e)
{
    int rsum=INT_MIN;
    int sum=0;
    for(int i = mid; i>=l; i--)
    {
        sum += v[i];
        if(sum>rsum){
            rsum=sum;
            s=i;
        }
    }
    int lsum=INT_MIN;
     sum=0;
    for(int i = mid+1; i<=r; i++)
    {
        sum += v[i];
        if(sum>lsum){
            lsum=sum;
            e=i;
        }
    }
    return rsum+lsum;
}
int maxsubarry(vector<int>& v, int l, int r,int & s, int & e)
{
    if(l==r) return v[l];
    int mid = (l+r)/2;
    int left = maxsubarry(v,l,mid,s,e);
    int right = maxsubarry(v,mid+1,r,s,e);
    int cross = crossSum(v,l,mid,r,s,e);
    return max(max(left,right),cross);

}
int main()
{
    vector<int> v = {2, -4, 3, 5, -1, 4};
    int n = v.size();
    int s=0,e=0;
    cout<<maxsubarry(v,0,n-1,s,e)<<endl;
    for(int i = s ; i<=e; i++) cout <<v[i]<<" ";

}