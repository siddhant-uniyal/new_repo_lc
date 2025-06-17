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
        if(minEdge == 4e6 + 1) return 0;
        unordered_set<int>st;
        cost += minEdge;
        st.insert(u);
        st.insert(v);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        vector<int>minEdge(n , 4e6 + 1);
        for(auto &[nxt , wt] : adj[u]){
            if(nxt == v) continue;
            pq.emplace(wt , nxt);
            minEdge[nxt] = wt;
        }
        for(auto &[nxt , wt] : adj[v]){
            if(nxt == u || minEdge[nxt] < wt) continue;
            pq.emplace(wt , nxt);
            minEdge[nxt] = wt;
        }
        while(st.size() < n){
            auto [wt , newNode] = pq.top();
            pq.pop();
            cost += wt;
            st.insert(newNode);
            for(auto& [nxt , wt] : adj[newNode]){
                if(!st.count(nxt)){
                    pq.emplace(wt , nxt);
                }
            }
        }
        return cost;
    }
};