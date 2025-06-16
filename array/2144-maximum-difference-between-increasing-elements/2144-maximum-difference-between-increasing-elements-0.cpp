class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int mn = nums[0];
        int ans = -1;
        for(int i = 1 ; i < (int)nums.size() ; ++i){
            ans = max(nums[i] - mn);
            mn = min(nums[i] , mn);
        }
        return ans;
    }
};