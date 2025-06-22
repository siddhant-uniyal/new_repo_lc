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
            int to_return = 0;
            for(int j = 0 ; amount - j * coins[idx] >= 0 ; ++j){
                to_return += self(amount - j * coins[idx] , idx + 1 , self);
            }
            return to_return;
        };

        for(int i = 0 ; i < n ; ++i){
            int amt = i + 1;
            int ways = numWays[i];
            int canMake = dfs(amt , 0 , dfs);
            if(canMake == ways - 1) coins.push_back(amt);
        }

        for(int i = 0 ; i < n ; ++i){
            int amt = i + 1;
            int ways = numWays[i];
            int canMake = dfs(amt , 0 , dfs);
            if(canMake != ways) return {};
        }

        return coins;
    }
};