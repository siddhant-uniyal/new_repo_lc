class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size();
        long s = accumulate(nums.begin() , nums.end() , 0L);
        long l = nums[0] , r = s + 1;
        while(l < r){
            long m = l + ((r-l)>>1);
            int ok = true;
            long prev = nums[0];
            for(int i = 1 ; i < n ; ++i){
                long diff = m - prev;
                long curr = max(0L , 1L*nums[i] - diff);
                if(curr > m){
                    ok = false;
                    break;
                }
                prev = curr;
            }
            if(ok) r = m;
            else l = m + 1;
        }
        return l;
    }
};