class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        /*
        dp[i] = cost to cover all the days from 1 to i
        but , some days from 1 to i could not be in days
        in that case , to cover those days , cost is just 
        dp[i - 1].
        eg : days = [1 , 2 , 5]
        cost to cover day 4 : i dont have to cover day 4 , so just consider the cost of previous day , day 3
        day 3 : dont have to cover , just consider day 2
        */
        vector<int>dp(days.back() + 1);
        dp[0] = 0;
        int j = 0;
        for(int i = 1 ; i <= days.back() ; ++i){
            if(days[j] == i){
                int oneDay = dp[i - 1] + costs[0];
                int sevenDays = (i >= 7 ? dp[i - 7] : 0) + costs[1];
                int thirtyDays = (i >= 30 ? dp[i - 30] : 0) + costs[2];
                dp[i] = min({oneDay , sevenDays , thirtyDays});
                ++j;
            }
            else{
                dp[i] = dp[i - 1];
            }
        }
        return dp.back();
    }
};