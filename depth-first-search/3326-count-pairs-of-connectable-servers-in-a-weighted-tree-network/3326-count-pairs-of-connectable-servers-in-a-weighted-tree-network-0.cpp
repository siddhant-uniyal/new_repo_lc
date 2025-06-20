class Solution {
public:
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        /*
        initial thoughts : 
        no common edges : lca 
        make each node lca
        but then how to update distances of every node from this node?
        
        had to see hint  

        fix each node as a root

        then , 
            0
        1 2 3 4 5 ...

        make every node in 1 subtree have pars[node] = 1
        iterate over these nodes , increment divCnt

        then do for 2. doing this ensures that 0 remains the lca. can't figure out a better way

        n^2
        
        major refactor : remove all extra space and inner loop , use 2 variables :
            divCnt : how many guys in the left subtrees (for 4 , 1;2;3 in above eg)
            increm : how many guys in this subtree
            so just divCnt * increm
        */
        
        int n = edges.size() + 1;
        vector<vector<pair<int,int>>>adj(n);
        for(auto &e : edges){
            adj[e[0]].emplace_back(e[1] , e[2]);
            adj[e[1]].emplace_back(e[0] , e[2]);
        }
        vector<int>ans(n);
        int divCnt = 0;
        int increm = 0;
        auto dfs = [&](int src , int par , int dist , auto &&self) -> void {
            if(dist && dist%signalSpeed == 0) ++increm;
            for(auto &[nxt , wt] : adj[src]){
                if(nxt == par) continue;
                self(nxt , src , dist + wt , self);
                if(par == -1){
                    ans[src] += increm*divCnt;
                    divCnt += increm;
                    increm = 0;
                }
            }
        };
        for(int i = 0 ; i < n ; ++i){
            divCnt = 0;
            increm = 0;
            dfs(i , -1 , 0 , dfs);
        }
        return ans;
    }
};