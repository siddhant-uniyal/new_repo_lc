class Solution {
public:
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        int j = n - 1;
        int i = 0;
        while(i < n && nums[i] <= 0) ++i;
        int posStart = i;
        --i;
        int sum = 0;
        int ans = 0;
        while(i >= 0 && j >= 0 && nums[j] > 0){
            sum += nums[j];
            ++ans;
            while(i >= 0 && sum + nums[i] > 0){
                ++ans;
                sum += nums[i];
                --i;
            }
            --j;
        }
        return ans + (j - posStart + 1);
    }
};