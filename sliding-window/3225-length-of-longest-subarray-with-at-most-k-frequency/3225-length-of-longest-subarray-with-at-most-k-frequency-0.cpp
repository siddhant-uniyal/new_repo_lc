class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mp;
        int i = 0 , j = 0;
        int ans = 1;
        while(j < n){
            ++mp[nums[j]];
            while(i <= j && mp[nums[j]] > k){
                --mp[nums[i]];
                if(mp[nums[i]] == 0) mp.erase(nums[i]);
                ++i;
            }
            ans = max(ans , j - i + 1);
            ++j;
        }
        return ans;
    }
};