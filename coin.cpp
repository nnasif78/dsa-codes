#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int minimumCoin(vector<int> coins,int ammount)
{
    vector<int>dp(ammount+1,ammount+1);
    dp[0]=0;
    for(int coin : coins){
        for(int i=1;i<=ammount;i++)
        {
            if(coin<=i)
            {
                dp[i]=min(dp[i],dp[i-coin]+1);
            }
        }
    }
    return dp[ammount];
}
int totalWays(vector<int> coins,int ammount)
{
    vector<int>dp(ammount+1,0);
    dp[0]=1;
    for(int coin : coins){
        for(int i=1;i<=ammount;i++)
        {
            if(coin<=i)
            {
                dp[i]+=dp[i-coin];
            }
        }
    }
    return dp[ammount];
}
int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 5;

    cout << "Total ways = " << totalWays(coins, amount)<<endl;
    cout<< "Minimum coins = " << minimumCoin(coins, amount)<<endl;
    return 0;
}