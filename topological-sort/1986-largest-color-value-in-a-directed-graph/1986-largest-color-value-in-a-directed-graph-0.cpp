class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        //check cycle
        int n = colors.size();
        vector<vector<int>>adj(n);
        vector<int>indeg(n);
        for(auto &v : edges){
            adj[v[0]].push_back(v[1]);
            ++indeg[v[1]];
        }
        queue<int>bfs;
        int topo = 0;
        for(int i = 0 ; i < n ; ++i){
            if(!indeg[i]){
                bfs.push(i);
            }
        }
        while(!bfs.empty()){
            int src = bfs.front();
            ++topo;
            bfs.pop();
            for(int nxt : adj[src]){
                --indeg[nxt];
                if(!indeg[nxt]) bfs.push(nxt);
            }
        }
        if(topo != n) return -1;
        //dfs , dp
        int ans = 0;
        unordered_map<int,vector<int>>dp;
        auto dfs = [&](int src , auto &&self) -> void {
            if(dp.count(src)) return;
            dp[src] = vector<int>(26);
            bool isLeaf = true;
            for(int nxt : adj[src]){
                isLeaf = false;
                self(nxt , self);
                for(int i = 0 ; i < 26 ; ++i){
                    dp[src][i] = max(dp[src][i] , dp[nxt][i] + (i == colors[src] - 'a'));
                }
            }
            if(isLeaf){
                ++dp[src][colors[src] - 'a'];
            }
        };
        for(int i = 0 ; i < n ; ++i){
            if(dp.count(i)) continue;
            dfs(i , dfs);
            ans = max(ans , *max_element(dp[i].begin() , dp[i].end()));
        }
        return ans;
    }
};