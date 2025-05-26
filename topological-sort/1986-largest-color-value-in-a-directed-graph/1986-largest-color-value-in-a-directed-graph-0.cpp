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
        int ans = 0;
        vector<int>vis(n);
        unordered_map<int,vector<int>>memo;
        auto dfs = [&](int src , auto &&self) -> vector<int> {
            if(memo.count(src)) return memo[src];
            vis[src] = 1;
            vector<int>to_return(26);
            for(int nxt : adj[src]){
                to_return = self(nxt , self);
                ++to_return[colors[src] - 'a'];
            }
            if(to_return.empty()){
                ++to_return[colors[src] - 'a'];
            }
            ans = max(ans , to_return[colors[src] - 'a']);
            return memo[src] = to_return;
        };
        for(int i = 0 ; i < n ; ++i){
            if(vis[i]) continue;
            dfs(i , dfs);
        }
        return ans;
    }
};