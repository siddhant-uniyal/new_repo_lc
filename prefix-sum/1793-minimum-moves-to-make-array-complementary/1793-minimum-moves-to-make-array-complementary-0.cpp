class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int sz = 2*limit + 1;
        vector<int>ops(sz);
        vector<int>zeroOps(sz);
        int n = nums.size();
        for(int i = 0 ; i < n/2 ; ++i){
            int curr = nums[i] + nums[n - 1 - i];
            int oneOp = max(nums[i] , nums[n - 1 - i]) + limit;
            ++zeroOps[curr];
            ++ops[curr];
            if(oneOp + 1 < sz) --ops[oneOp + 1];
        }
        int ans = n + 1;
        for(int i = 2 ; i <= 2*limit ; ++i){
            ops[i] += ops[i - 1];
            int total = ops[i] - zeroOps[i] + 2*(n/2 - ops[i]);
            ans = min(ans , total);
        }
        return ans;
    }
};