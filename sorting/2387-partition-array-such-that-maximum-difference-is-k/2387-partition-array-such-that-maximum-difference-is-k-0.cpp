class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        //like 763 , additional constraint. sort
        sort(nums.begin() , nums.end());
        int n = nums.size();
        int ans = 1;
        int i = 0;
        for(int j = 0 ; j < n ; ){
            if(nums[j] - nums[i] > k){
                i = j;
                ++ans;
            }
            int k = j + 1;
            while(k < n && nums[k] == nums[j]) ++k;
            j = k;
        }
        return ans;
    }
};