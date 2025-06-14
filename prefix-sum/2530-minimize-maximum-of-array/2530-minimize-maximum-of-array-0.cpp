class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size();
        int s = accumulate(nums.begin() , nums.end() , 0);
        int l = nums[0] , r = s + 1;
        while(l < r){
            int m = l + ((r-l)>>1);
            int ok = true;
            vector<int>cpy = nums;
            for(int i = 1 ; i < n ; ++i){
                int diff = m - cpy[i - 1];
                cpy[i] -= diff;
                if(cpy[i] > m){
                    ok = false;
                }
            }
            if(ok) r = m;
            else l = m + 1;
        }
        return l;
    }
};