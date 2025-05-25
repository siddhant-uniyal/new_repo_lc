using ll = long long;
class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>>adj(n);
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
        }
        auto dfs = [&](int src , int par , auto &&self) -> long long{
            int posDeltaCnt = 0;
            ll posDeltaSum = 0;
            ll minPosDelta = LONG_MAX;
            ll valSrc = nums[src];
            ll sum = valSrc;
            bool isLeaf = true;
            for(int nxt : adj[src]){
                isLeaf = false;
                if(nxt == par) continue;
                sum += self(nxt , src , self);
                if((valSrc^k) > valSrc){
                    ll nxtDelta = (nums[nxt]^k) - (nums[nxt]);
                    if(nxtDelta > 0){
                        ++posDeltaCnt;
                        posDeltaSum += nxtDelta;
                        minPosDelta = min(minPosDelta , nxtDelta);
                    }
                }
            }
            if(isLeaf) return valSrc;
            ll to_return = sum;
            if((valSrc^k) <= valSrc) return to_return;
            to_return += posDeltaSum;
            if(!(posDeltaCnt&1)) to_return -= minPosDelta;
            return (valSrc^k) - (valSrc) + to_return;
        };
        return dfs(0 , 0 , dfs);
    }
};