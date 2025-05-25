class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>>fromHere(n , vector<int>(3 , 0));
        vector<vector<int>>memo(n , vector<int>(3 , -1));
        vector<int>pref(n);
        for(int i = 0 ; i < n ; ++i){
            pref[i] = (i ? pref[i - 1] : 0) + nums[i];
        }
        auto dfs = [&](int ind , int arr , auto &&self) -> int{
            if(ind == n){
                return arr == 3 ? 0 : INT_MIN;
            }
            if(arr == 3){
                return 0;
            }
            if(memo[ind][arr] != -1) return memo[ind][arr];
            int take = INT_MIN;
            if(ind + k <= n){
                int l = ind ? pref[ind - 1] : 0;
                int r = pref[ind + k - 1];
                take = (r - l) + self(ind + k , arr + 1 , self);
            }
            int skip = self(ind + 1 , arr , self);
            if(take >= skip) fromHere[ind][arr] = 1;
            return memo[ind][arr] = max(take , skip);
        };
        dfs(0 , 0 , dfs);
        vector<int>ans;
        int ptr = 0 , arr = 0;
        while(ptr < n && arr < 3){
            if(!fromHere[ptr][arr]) ++ptr;
            else{
                ans.push_back(ptr);
                ptr += k;
                ++arr;
            }
        }
        return ans;
    }
};