class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        /*
        find something for a node , wrt to all nodes pattern
        1st pass dfs : find it for all nodes , only for subtrees
        2nd pass : then , inorder : each node refers to parent answer
        */
        int n = (int)edges1.size() + 1;
        int m = (int)edges2.size() + 1;
        vector<vector<int>>data1(2 , vector<int>(n , 0));
        vector<vector<int>>data2(2 , vector<int>(m , 0));
        auto dfs = [&](int src , int par , int prt , int mode , vector<vector<int>>& adj , vector<vector<int>>& data , auto &&self) -> pair<int,int>{
            if(mode && par != -1){
                for(int k = 0 ; k < 2 ; ++k){
                    data[k][src] += (data[!k][par] - data[k][src]);
                }
            }
            pair<int,int> to_return = {(!prt) , 1}; //prt Cnt , subtree cnt
            for(int nxt : adj[src]){
                if(nxt == par) continue;
                pair<int,int>res = self(nxt , src , !prt , mode , adj , data , self);
                to_return.first += res.first;
                to_return.second += res.second;
            }
            if(!mode){
                data[prt][src] = to_return.first;
                data[!prt][src] = to_return.second - data[prt][src];
            }
            
            return to_return;
        };
        auto getAdj = [&](vector<vector<int>>& edges) -> vector<vector<int>> {
            int n = (int)edges.size() + 1;
            vector<vector<int>>adj(n);
            for(auto &v : edges){
                adj[v[0]].push_back(v[1]);
                adj[v[1]].push_back(v[0]);
            }
            return adj;
        };

        vector<vector<int>>adj1 = getAdj(edges1);
        vector<vector<int>>adj2 = getAdj(edges2);

        dfs(0 , -1 , 0 , 0 , adj1 , data1 , dfs);
        dfs(0 , -1 , 0 , 1 , adj1 , data1 , dfs);
        dfs(0 , -1 , 0 , 0 , adj2 , data2 , dfs);
        dfs(0 , -1 , 0 , 1 , adj2 , data2 , dfs);

        int mx = *max_element(data2[1].begin() , data2[1].end());

        for(int i = 0 ; i < n ; ++i){
            data1[0][i] += mx;
        }

        return data1[0];
    }
};
