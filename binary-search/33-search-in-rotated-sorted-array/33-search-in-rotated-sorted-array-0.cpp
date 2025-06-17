class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n;
        /*
        find which half m is in
        if same half as target , normal bs logic
        else , just go to the other half
        */
        while (l < r) {
            int m = l + ((r - l) >> 1);
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
        return l == n || nums[l] != target ? -1 : l;
    }
};