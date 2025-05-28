int dp[100000][26];
class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        //dfs , dp , check cycle
        //for tabulation , must do topo sort
        //it gives bottom up order (outdeg = 0)
        int ans = 0;
        int n = colors.size();
        vector<vector<int>>adj(n);
        for(auto &v : edges){
            adj[v[0]].push_back(v[1]);
        }
        vector<int>topo;
        memset(dp , 0 , sizeof(dp));
        vector<int>vis(n);
        auto topoSort = [&](int src , auto &&self) -> int{
            if(vis[src] == 1) return -1;
            if(vis[src] == 2) return 1;
            vis[src] = 1;
            for(int nxt : adj[src]){
                if(self(nxt , self) == -1) return -1;
            }
            topo.push_back(src);
            vis[src] = 2;
            return 1;
        };
        for(int i = 0 ; i < n ; ++i){
            if(vis[i] == 2) continue;
            if(topoSort(i , topoSort) == -1) return -1;
        }
        for(int i = 0 ; i < n ; ++i){
            bool isLeaf = true;
            int src = topo[i];
            for(int nxt : adj[src]){
                isLeaf = false;
                for(int k = 0 ; k < 26 ; ++k){
                    dp[src][k] = max(dp[src][k] , dp[nxt][k] + (k == colors[src] - 'a'));
                    ans = max(ans , dp[src][k]);
                }
            }
            if(isLeaf) dp[src][colors[src] - 'a'] = 1 , ans = max(ans , 1);
        }
        return ans;
    }
};