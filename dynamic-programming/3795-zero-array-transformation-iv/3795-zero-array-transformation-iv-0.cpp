// class Solution {
// public:
//     int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
//         int n = nums.size();
//         int sz = queries.size();
//         int l = 0 , r = sz + 1;
//         while(l < r){
//             int m = l + ((r-l)>>1);
//             bool ok = true;
//             vector<vector<int>>vals(n);
//             for(int i = 0 ; i < m ; ++i){
//                 for(int j = queries[i][0] ; j <= queries[i][1] ; ++j){
//                     vals[j].push_back(queries[i][2]);
//                 }
//             }
//             for(int i = 0 ; i < n ; ++i){
//                 if(!nums[i]) continue;
//                 int valCnt = vals[i].size();
//                 vector<vector<bool>>dp(valCnt + 1 , vector<bool>(nums[i] + 1 , false));
//                 dp[0][0] = true;
//                 for(int j = 1 ; j <= valCnt ; ++j){
//                     for(int k = 0 ; k <= nums[i] ; ++k){
//                         bool fill = dp[j - 1][k];
//                         if(vals[i][j - 1] <= k){
//                             fill |= dp[j - 1][k - vals[i][j-1]];
//                         }
//                         dp[j][k] = fill;
//                     }
//                 }
//                 if(!dp[valCnt][nums[i]]){
//                     ok = false;
//                     break;
//                 }
//             }
//             if(ok) r = m;
//             else l = m + 1;
//         }
//         return l == sz + 1 ? -1 : l;
//     }
// };

class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), sz = queries.size();
        int l = 0, r = sz + 1;
        
        while (l < r) {
            int m = (l + r) / 2;
            vector<vector<int>> vals(n);
            for (int i = 0; i < m; ++i) {
                for (int j = queries[i][0]; j <= queries[i][1]; ++j) {
                    vals[j].push_back(queries[i][2]);
                }
            }
            
            bool ok = true;
            for (int i = 0; i < n && ok; ++i) {
                if (nums[i] == 0) continue;
                int target = nums[i];
                bitset<10001> bs;
                bs[0] = 1;
                for (int v : vals[i]) {
                    bs |= (bs << v);
                }
                if (!bs[target]) {
                    ok = false;
                }
            }

            if (ok) r = m;
            else l = m + 1;
        }

        return l == sz + 1 ? -1 : l;
    }
};
