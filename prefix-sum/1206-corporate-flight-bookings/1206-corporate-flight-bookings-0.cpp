class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>ans(n);
        for(auto &v : bookings){
            ans[v[0]] += v[2];
            if(v[1] + 1 < n) ans[v[1]] -= v[2];
        }   
        for(int i = 1 ; i < n ; ++i) ans[i] += ans[i - 1];
        return ans;
    }
};