class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size();
        for(int i = n - 1 ; i >= 1 ; --i){
            if(nums[i] > nums[i - 1]){
                int sum = nums[i] + nums[i - 1];
                nums[i] = sum/2;
                nums[i - 1] = sum/2 + (sum&1);
            }
        }
        // for(int i : nums) cout << i << " ";
        return *max_element(nums.begin() , nums.end());
    }
};