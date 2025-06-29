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
        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < n ; ++j){
                if(i == j) continue;
                int dist = getDist(i , j);
                adj[i].push_back(make_pair(j , dist));
                adj[j].push_back(make_pair(i , dist));
            }
        }
        unordered_set<int>st;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        pq.emplace(0 , 0);
        while(st.size() < n){
            auto [wt , newNode] = pq.top();
            pq.pop();
            if(st.count(newNode)) continue;
            cost += wt;
            st.insert(newNode);
            for(auto& [nxt , wt] : adj[newNode]){
                if(!st.count(nxt)){
                    pq.emplace(wt , nxt);
                    minEdges[nxt] = wt;
                }
            }
        }
        return cost;
    }
};