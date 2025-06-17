class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n;
        while (l < r) {
            int m = l + ((r - l) >> 1);
            if(nums[m] == target) return m;
            bool b1 = nums[m] >= nums[0];
            bool b2 = target >= nums[0];
            if (b1 ^ b2) {
                if(b1) l = m + 1;
                else r = m;
            } else {
                if(nums[m] < target) l = m + 1;
                else r = m;
            }
        }
        return -1;
    }
};