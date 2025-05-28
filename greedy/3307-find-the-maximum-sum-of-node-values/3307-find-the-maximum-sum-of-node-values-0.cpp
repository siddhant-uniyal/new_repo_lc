using ll = long long;
class Solution {
public:
    ll maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
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

        but if only 1 inc : get max neg delta
        */
        ll ans = 0;
        ll minDelta = INT_MAX;
        ll maxNegDelta = INT_MIN;
        int incs = 0;
        for(int i : nums){
            ans += i;
            ll delta = (i^k) - i;
            if(delta > 0){
                ++incs;
                ans += delta;
                minDelta = min(minDelta , delta);
            }
            else maxNegDelta = max(maxNegDelta , delta);
        }
        ll pos1 = ans - (incs&1 ? minDelta : 0);
        ll pos2 = ans + maxNegDelta;
        return max(pos1 , pos2);
    }
};