class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        /*
        sum doesnt change
        n - 1 to 0 : shift everything , nums[0] becomes s
        so max upper bound is s
        lower bound is actually nums[0] , because its the only elem that can only increase
        then bs , maintain open slots , basically how much i can take away from the current element to make it <= m , and ensure that elems to left are still <= m.
        */
        int n = nums.size();
        long s = accumulate(nums.begin() , nums.end() , 0L);
        long l = nums[0] , r = s + 1;
        while(l < r){
            long m = l + ((r-l)>>1);
            int ok = true;
            long open = m - nums[0];
            for(int i = 1 ; i < n ; ++i){
                if(nums[i] - open > m){
                    ok = false;
                    break;
                }
                if(nums[i] > m) open -= (nums[i] - m);
                else open += m - nums[i];
            }
            if(ok) r = m;
            else l = m + 1;
        }
        return l;
    }
};