class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        /*
        find something for a node , wrt to all nodes pattern
        1st pass dfs : find it for all nodes , only for subtrees
        2nd pass : then , inorder : each node refers to parent answer
        this is unnecessarily complex : just get (evens , odds) from child
        then add evens to parents odds and vice versa

        better :
            fix 0 as root , get depths of all
            if my depth odd/even : all odd/even depths are targets
        */
        int n = (int)edges1.size() + 1;
        int m = (int)edges2.size() + 1;
        vector<int>data1(n);
        vector<int>data2(m);
        int depths1[2] = {0};
        int depths2[2] = {0};
        auto dfs = [&](int src , int par , int depth , vector<vector<int>>& adj , vector<int>& data , int* depths , auto &&self) -> void{
            ++depths[depth];
            data[src] = depth;
            for(int nxt : adj[src]){
                if(nxt == par) continue;
                self(nxt , src , !depth , adj , data , depths, self);
            }
            return;
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

        dfs(0 , -1 , 0 , adj1 , data1 , depths1 , dfs);
        dfs(0 , -1 , 0 , adj2 , data2 , depths2 , dfs);

        int mx = -1;
        set<int>st;
        for(int i = 0 ; i < m ; ++i){
            mx = max(mx , depths2[data2[i]]);
            st.insert(depths2[data2[i]]);
        }
        assert((int)st.size() <= 2);
        for(int i = 0 ; i < n ; ++i){
            int prt = data1[i];
            data1[i] = depths1[prt] + mx;
        }
        return data1;
    }
};
