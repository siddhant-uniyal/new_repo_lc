class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        /*
        k level bfs on tree1: initial ans
        k - 1 level bfs on tree2 : get max
        add to each element
        */
        auto levelBFS = [&](int k , vector<vector<int>>& adj){
            int n = adj.size();
            vector<int>res(n);
            queue<pair<int,int>>bfs;
            for(int i = 0 ; i < n ; ++i){
                bfs.emplace(i,i);
                int target = 0;
                for(int j = 0 ; j <= k ; ++j){
                    target += (int)bfs.size();
                    int sz = bfs.size();
                    while(sz--){
                        auto [src , par] = bfs.front();
                        bfs.pop();
                        for(int nxt : adj[src]){
                            if(nxt == par) continue;
                            bfs.emplace(nxt , src);
                        }
                    }
                }
                // queue<pair<int,int>>().swap(bfs);
                res[i] = target;
            }
            return res;
        };
        auto createAdj = [&](vector<vector<int>>& edges){
            int n = (int)edges.size() + 1;
            vector<vector<int>>adj(n);
            for(auto& e : edges){
                adj[e[0]].push_back(e[1]);
                adj[e[1]].push_back(e[0]);
            }
            return adj;
        };
        vector<vector<int>>adj1 = createAdj(edges1);
        vector<vector<int>>adj2 = createAdj(edges2);
        vector<int>res1 = levelBFS(k , adj1);
        vector<int>res2 = levelBFS(k - 1 , adj2);
        int mx = *max_element(res2.begin() , res2.end());
        for(int &i : res1) i += mx;
        return res1;
    }
};