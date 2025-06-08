class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;
        for(int i = 0 ; i + 1 < n ; ++i){
            if(nums[i] == -1){
                if(cnt == k) return false;
                nums[i] = 1;
                nums[i + 1] *= -1;
                ++cnt;
            }
        }
        for(int i = 0 ; i < n ; ++i) if(nums[i] == -1) return false;
        return true;
    }
};