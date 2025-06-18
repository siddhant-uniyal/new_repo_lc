class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //best guy is prefix minimum
        int mn = 1e4 + 1;
        int ans = 0;
        for(int i : prices){
            ans = max(ans , i - mn);
            mn = min(i , mn);
        }
        return ans;
    }
};