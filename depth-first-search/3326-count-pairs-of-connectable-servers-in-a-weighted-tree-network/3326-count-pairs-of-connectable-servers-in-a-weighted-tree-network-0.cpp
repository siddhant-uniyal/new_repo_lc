class Solution {
public:
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        int n = edges.size() + 1;
        vector<vector<pair<int,int>>>adj(n);
        for(auto &e : edges){
            adj[e[0]].emplace_back(e[1] , e[2]);
            adj[e[1]].emplace_back(e[0] , e[2]);
        }
        vector<int>ans(n);
        vector<int>pars(n);
        vector<int>dists(n);
        int divCnt = 0;
        auto dfs = [&](int src , int par , int root , int dist , auto &&self) -> void {
            dists[src] = dist;
            pars[src] = root;
            int childCnt = 0;
            for(auto &[nxt , wt] : adj[src]){
                if(nxt == par) continue;
                ++childCnt;
                self(nxt , src , par == -1 ? nxt : root , dist + wt , self);
                if(par == -1){
                    // if(src == 1){
                    //     for(int i = 0 ; i < n ; ++i){
                    //         cout << pars[i] << " ";
                    //     }
                    //     cout << endl;
                    //     for(int i = 0 ; i < n ; ++i){
                    //         cout << dists[i] << " ";
                    //     }
                    //     cout << endl;
                    // }
                    int increm = 0;
                    for(int i = 0 ; i < n ; ++i){
                        if(pars[i] != nxt) continue;
                        if(dists[i]%signalSpeed == 0){
                            if(childCnt > 1) ans[src] += divCnt;
                            ++increm;
                        }
                    }
                    divCnt += increm;
                }
            }
        };
        for(int i = 0 ; i < n ; ++i){
            fill(pars.begin() , pars.end() , -1);
            fill(dists.begin() , dists.end() , 0);
            divCnt = 0;
            dfs(i , -1 , i , 0 , dfs);
        }
        return ans;
    }
};