const int MOD = 1e9 + 7;
class Solution {
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>>adj(n);
        for(auto &e : edges){
            adj[e[0] - 1].push_back(e[1] - 1);
            adj[e[1] - 1].push_back(e[0] - 1);
        }
        int depth = 0;
        auto dfs = [&](int src , int par , int curr , auto &&self) -> void{
            depth = max(depth , curr);
            for(int nxt : adj[src]){
                if(nxt == par) continue;
                self(nxt , src , curr + 1 , self);
            }
        };
        dfs(0 , 0 , 0 , dfs);
        int ans = 0;
        vector<int>facts(depth + 1);
        facts[0] = 1;
        for(int i = 1 ; i <= depth ; ++i){
            facts[i] = facts[i - 1] * i;
            facts[i] %= MOD;
        }
        auto binExp = [&](int a , int b) -> int{
            int res = 1;
            while(b){
                if(b&1){
                    res *= a;
                    res %= MOD;
                }
                b>>=1;
                a *= a;
                a %= MOD;
            }
            return res;
        };
        auto ncr = [&](int n , int r) -> int{
            int numer = facts[n];
            int denom1 = facts[n - r];
            int denom2 = facts[r];
            int prod = denom1 * denom2;
            prod %= MOD;
            int inv = binExp(prod , MOD - 2);
            numer *= inv;
            numer %= MOD;
            return numer;
        };
        for(int i = 1 ; i <= depth - !(depth&1) ; ++i){
            ans += ncr(depth , i);
            ans %= MOD;
        }
        return ans;
    }
};