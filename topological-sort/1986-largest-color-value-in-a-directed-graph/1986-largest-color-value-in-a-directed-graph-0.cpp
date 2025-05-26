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
                bfs.push(nxt);
            }
        }
        if(topo != n) return -1;
        int ans = 0;
        vector<int>vis(n);
        vector<int>occ(26);
        auto dfs = [&](int src , vector<int>& occ , auto &&self) -> void{
            ++occ[colors[src] - 'a'];
            int mx = -1;
            for(int i : occ) mx = max(mx , i);
            ans = max(ans , mx);
            vis[src] = 1;
            for(int nxt : adj[src]){
                self(nxt , occ , self);
            }
            --occ[colors[src] - 'a'];
        };
        for(int i = 0 ; i < n ; ++i){
            if(vis[i]) continue;
            fill(occ.begin() , occ.end() , 0);
            dfs(i , occ , dfs);
        }
        return ans;
    }
};