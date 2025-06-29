class Solution {
public:
    vector<int> findCoins(vector<int>& numWays) {
        int n = numWays.size();
        vector<int>coins;

        auto dfs = [&](int amount , int idx , auto &&self) -> int{
            if(amount == 0){
                return 1; 
            }
            if(idx >= (int)coins.size()) return 0;
            int take = coins[idx] <= amount ? self(amount - coins[idx] , idx, self) : 0;
            int skip = self(amount , idx + 1 , self);
            return take + skip;
        };

        for(int i = 0 ; i < n ; ++i){
            int amt = i + 1;
            int ways = numWays[i];
            int canMake = dfs(amt , 0 , dfs);
            if(canMake == ways - 1) coins.push_back(amt);
            else if(canMake != ways) return {};
        }

        return coins;
    }
};