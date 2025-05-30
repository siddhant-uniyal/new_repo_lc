class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int>vis(n);
        auto dfs = [&](int src , vector<int> &path , auto &&self) -> void{
            path.push_back(src);
            vis[src] = 1;
            if(edges[src] == -1) return;
            if(vis[edges[src]] == 1) return;
            self(edges[src] , path , self);
        };
        vector<int>path1 , path2;
        dfs(node1 , path1 , dfs);
        fill(vis.begin() , vis.end() , 0);
        dfs(node2 , path2 , dfs);
        int ans = n + 1;
        vector<int>dist(n , -1);
        for(int i = 0 ; i < (int)path1.size() ; ++i){
            dist[path1[i]] = i;
        }
        set<int>st;
        for(int i = 0 ; i < (int)path2.size() ; ++i){
            if(dist[path2[i]] != -1){
                int res = max(dist[path1[i]] , i);
                if(res <= ans){
                    if(res < ans) st.clear();
                    st.insert(path2[i]);
                    ans = res;
                }
            }
        }
        return st.empty() ? -1 : *st.begin();
    }
};