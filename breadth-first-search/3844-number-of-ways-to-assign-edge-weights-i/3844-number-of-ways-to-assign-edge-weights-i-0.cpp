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
            long long res = 1;
            long long xa = a;
            while(b){
                if(b&1){
                    res *= xa;
                    res %= MOD;
                }
                b>>=1;
                xa *= xa;
                xa %= MOD;
            }
            return (int)res;
        };
        auto ncr = [&](int n , int r) -> int{
            long long numer = facts[n];
            long long denom1 = facts[n - r];
            long long denom2 = facts[r];
            long long prod = denom1 * denom2;
            prod %= MOD;
            long long inv = binExp(prod , MOD - 2);
            numer *= inv;
            numer %= MOD;
            return (int)numer;
        };
        for(int i = 1 ; i <= depth - !(depth&1) ; i+=2){
            ans += ncr(depth , i);
            ans %= MOD;
        }
        return ans;
    }
};