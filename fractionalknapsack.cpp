#include<iostream>
#include<algorithm>
using namespace std;
struct items
{
    int value;
    int weight;
    double ratio;
};
bool compare(items a,items b){
    return a.ratio>b.ratio;
}
void fractionalKnapsack(items item[], int totalItems, int capacity)
{
    for(int i=0;i<totalItems;i++)
    {
        item[i].ratio= (double)item[i].value/item[i].weight;
    }
    sort(item,item+totalItems,compare);
    double totalProfit=0;
    for(int i=0;i<totalItems;i++)
    {
        if(item[i].weight<=capacity)
        {
            totalProfit += item[i].value;
            capacity-=item[i].weight; 
        }
        else{
            double fraction = (double)capacity/item[i].weight;
            totalProfit += fraction*item[i].value;
            capacity=0;
        }
    }
    cout<<totalProfit;
}
int main(){
items item[] = {{60, 10},{100, 20},{120, 30}};
fractionalKnapsack(item, 3, 50);
}