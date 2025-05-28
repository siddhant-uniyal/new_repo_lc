int dp[100000][26];
class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        //dfs , dp , check cycle
        int ans = 0;
        int n = colors.size();
        vector<vector<int>>adj(n);
        for(auto &v : edges){
            adj[v[0]].push_back(v[1]);
        }
        memset(dp , 0 , sizeof(dp));
        vector<int>vis(n);
        auto dfs = [&](int src , auto &&self) -> int {
            if(vis[src] == 2) return 1;
            if(vis[src] == 1) return -1; //part of current component
            vis[src] = 1; //mark as active
            bool isLeaf = true;
            for(int nxt : adj[src]){
                isLeaf = false;
                int ok = self(nxt , self);
                if(ok == -1) return -1;
                for(int i = 0 ; i < 26 ; ++i){
                    dp[src][i] = max(dp[src][i] , dp[nxt][i] + (i == colors[src] - 'a'));
                }
            }
            if(isLeaf){
                dp[src][colors[src] - 'a'] = 1;
            }
            vis[src] = 2; //mark as inactive, completely closed
            return 1;
        };
        for(int i = 0 ; i < n ; ++i){
            if(vis[i] == 2) continue;
            if(dfs(i , dfs) == -1) return -1;
            for(int j = 0 ; j < 26 ; ++j){
                ans = max(ans , dp[i][j]);
            }
        }
        return ans;
    }
};