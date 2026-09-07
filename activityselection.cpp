#include<iostream>
#include<algorithm>
using namespace std;
struct Activities
{
    int start;
    int end;
};
bool compare(Activities a, Activities b)
{
    return a.end<b.end;
}
int ActivitieSelection(Activities arr[], int n)
{
    sort(arr,arr+n,compare);
    int lastfinish=arr[0].end;
    int count =1;
    cout<<"---------------Selected Activities--------------"<<endl<<"Start  End"<<endl;
    cout<<arr[0].start<<"       "<<arr[0].end<<endl;
    for(int i=1;i<n;i++)
    {
        if(arr[i].start>=lastfinish)
        {
            count++;
            lastfinish = arr[i].end;
            cout<<arr[i].start<<"       "<<arr[i].end<<endl;
        }
    }
    return count;
}
int main()
{
    
    Activities arr[] = {
        {1, 2},
        {3, 4},
        {0, 6},
        {5, 7},
        {8, 9},
        {5, 9}
    };

    cout <<"Total Activities is : "<< ActivitieSelection(arr, 6);

    return 0;
}