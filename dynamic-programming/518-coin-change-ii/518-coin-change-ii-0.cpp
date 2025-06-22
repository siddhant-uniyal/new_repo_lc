class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int dp[5001][301];
        memset(dp , -1 , sizeof(dp));
        auto dfs = [&](int amount , int idx , auto &&self) -> int{
            if(amount == 0){
                return 1; 
            }
            if(idx >= (int)coins.size()) return 0;
            int take = coins[idx] <= amount ? self(amount - coins[idx] , idx] , self) : 0;
            int skip = self(amount , idx + 1 , self);
            return dp[amount][idx] = take + skip;
        };
        return dfs(amount , 0 , dfs);
    }
};