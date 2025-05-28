int dp[100000][26];
class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        //dfs , dp , check cycle
        //for tabulation , must do topo sort
        //it gives bottom up order (outdeg = 0)
        /*
        why dfs topo better than bfs topo :
        stack frame for recursion call > heap allocation for bfs queue
        */
        int ans = 0;
        int n = colors.size();
        vector<vector<int>>adj(n);
        vector<int>indeg(n);
        for(auto &v : edges){
            adj[v[0]].push_back(v[1]);
            ++indeg[v[1]];
        }
        queue<int>bfs;
        vector<int>topo;
        for(int i = 0 ; i < n ; ++i){
            if(!indeg[i]){
                bfs.push(i);
            }
        }
        while(!bfs.empty()){
            int src = bfs.front();
            topo.push_back(src);
            bfs.pop();
            for(int nxt : adj[src]){
                --indeg[nxt];
                if(!indeg[nxt]) bfs.push(nxt);
            }
        }
        if((int)topo.size() != n) return -1;
        memset(dp , 0 , sizeof(dp));
        for(int i = n - 1 ; i >= 0 ; --i){
            bool isLeaf = true;
            int src = topo[i];
            for(int nxt : adj[src]){
                isLeaf = false;
                for(int k = 0 ; k < 26 ; ++k){
                    dp[src][k] = max(dp[src][k] , dp[nxt][k] + (k == colors[src] - 'a'));
                }
            }
            if(isLeaf) dp[src][colors[src] - 'a'] = 1;
        }
        for(int i = 0 ; i < 26 ; ++i) ans = max(ans , dp[topo[0]][i]);
        return ans;
    }
};