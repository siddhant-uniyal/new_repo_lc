class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        int i = 1;
        //try monoton inc
        int eqs = 1;
        while(i < n && nums[i] >= nums[i - 1]) eqs += (nums[i] == nums[i -1]) , ++i;
        if(i == n) return true;
        if(eqs != i) return false;
        //it has to be < now
        while(i < n && nums[i] <= nums[i - 1]) ++i;
        return i == n;
    }
};