class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount + 1);
        for(int i = 1 ; i < amount + 1 ; ++i){
            dp[i] = amount + 1;
            for(int j : coins){
                if(j > i) continue;
                dp[i] = min(dp[i] , dp[i - j] + 1);
            }
        }
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};