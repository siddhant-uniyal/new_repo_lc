class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // vector<int>order;
        int dp[5001][301];
        memset(dp , -1 , sizeof(dp));
        auto dfs = [&](int amount , int idx , auto &&self) -> int{
            if(amount == 0){
                // for(int j : order) cout << j << " ";
                // cout << endl;
                return 1; 
            }
            if(idx >= (int)coins.size()) return 0;
            if(dp[amount][idx] != -1) return dp[amount][idx];
            int to_return = 0;
            for(int j = 0 ; amount - j * coins[idx] >= 0 ; ++j){
                // order.push_back(coins[idx]);
                to_return += self(amount - j * coins[idx] , idx + 1 , self);
                // order.pop_back();
            }
            return dp[amount][idx] = to_return;
        };
        return dfs(amount , 0 , dfs);
    }
};