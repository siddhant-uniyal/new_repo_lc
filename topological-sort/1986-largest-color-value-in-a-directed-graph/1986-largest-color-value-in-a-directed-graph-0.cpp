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
        vector<int>vis(n);
        unordered_map<int,vector<int>>memo;
        auto dfs = [&](int src , auto &&self) -> vector<int> {
            if(memo.count(src)) return memo[src];
            vis[src] = 1;
            vector<int>to_return(26);
            bool isLeaf = true;
            for(int nxt : adj[src]){
                isLeaf = false;
                vector<int>res = self(nxt , self);
                for(int i = 0 ; i < 26 ; ++i){
                    to_return[i] = max(to_return[i] , res[i] + (i == colors[src] - 'a'));
                }
            }
            if(isLeaf){
                ++to_return[colors[src] - 'a'];
            }
            return memo[src] = to_return;
        };
        for(int i = 0 ; i < n ; ++i){
            if(vis[i]) continue;
            vector<int>res = dfs(i , dfs);
            ans = max(ans , *max_element(res.begin() , res.end()));
        }
        return ans;
    }
};