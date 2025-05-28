class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        /*
        a -> b -> c -> d ..

        want to change a because it increases after XOR : b changes too
        to undo : c changes
        so XOR gets passed around
        if theres another element that increases , just pass it
        if theres 3 ? one XOR remains

        so any pair of nodes can be resolved :
        node1 -> lca -> node2 : pass it

        so even number of increases : all can be increased
        else , cant increase 1
        so add all increases , subtract minimum delta if odd
        */
        long long ans = 0;
        long long minDelta = INT_MAX;
        int incs = 0;
        for(int i : nums){
            ans += i;
            long long delta = (i^k) - i;
            if(delta > 0){
                ++incs;
                ans += delta;
                minDelta = min(minDelta , delta);
            }
        }
        return ans - (incs&1 ? minDelta : 0);
    }
};