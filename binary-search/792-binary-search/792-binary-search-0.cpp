class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0 , r = n;
        while(l < r){
            int m = l + ((r-l)>>1);
            if(nums[m] >= target) r = m;
            else l = m + 1;
        }
        return l == n || nums[l] != target ? -1 : l;
    }
};