class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int ans = 0;
        vector<int>candies(n);
        for(int i = 0 ; i < n ; ++i){
            candies[i] = 1;
            if(i && ratings[i] > ratings[i - 1]){
                candies[i] = candies[i - 1] + 1;
            }
        }
        for(int i = n - 2 ; i >= 0 ; --i){
            if(ratings[i] > ratings[i + 1]){
                candies[i] = candies[i + 1] + 1;
            }
        }
        return accumulate(candies.begin() , candies.end() , 0);
    }
};