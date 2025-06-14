class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size();
        int s = accumulate(nums.begin() , nums.end() , 0);
        int l = nums[0] , r = s + 1;
        while(l < r){
            int m = l + ((r-l)>>1);
            int ok = true;
            for(int i = 1 ; i < n ; ++i){
                if(nums[i] > m){
                    int diff = nums[i] - m;
                    if(nums[i - 1] + diff > m){
                        ok = false;
                        break;
                    }
                }
            }
            if(ok) r = m;
            else l = m + 1;
        }
        return l;
    }
};