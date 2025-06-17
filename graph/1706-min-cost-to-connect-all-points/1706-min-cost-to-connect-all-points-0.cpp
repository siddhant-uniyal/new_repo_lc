class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        // mst
        int n = points.size();
        vector<vector<pair<int,int>>>adj(n);
        auto getDist = [&](int i , int j) -> int{
            return abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
        };
        int cost = 0;
        int u , v;
        int minEdge = 4 * 1e6 + 1;
        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < n ; ++j){
                if(i == j) continue;
                int dist = getDist(i , j);
                adj[i].push_back(make_pair(j , dist));
                adj[j].push_back(make_pair(i , dist));
                if(dist < minEdge){
                    u = i , v = j;
                    minEdge = dist;
                }
            }
        }
        unordered_set<int>st;
        cost += minEdge;
        st.insert(u);
        st.insert(v);
        while(st.size() != n){
            int x = 0;
            minEdge = 4e6 + 1;
            for(auto &i : st){
                for(auto& [nxt , wt] : adj[i]){
                    if(!st.count(nxt) && wt < minEdge){
                        minEdge = wt;
                        x = nxt;
                    }
                }
            }
            cost += minEdge;
            st.insert(x);
        }
        return cost;
    }
};