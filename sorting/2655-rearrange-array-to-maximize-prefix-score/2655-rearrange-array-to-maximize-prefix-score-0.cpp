class Solution {
public:
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>data(2);
        for(int i = 0 ; i < n ; ++i){
            data[nums[i] > 0].push_back(nums[i]);
        }
        sort(data[0].rbegin() , data[0].rend());
        sort(data[1].rbegin() , data[1].rend());
        int i = 0 , j = 0;
        int sum = 0;
        vector<int>order;
        int ans = 0;
        while(i < data[0].size() && j < data[1].size()){
            order.push_back(data[1][j]);
            sum += order.back();
            ++ans;
            while(i < data[0].size() && sum + data[0][i] > 0){
                ++ans;
                sum += data[0][i];
                order.push_back(data[0][i]);
                ++i;
            }
            ++j;
        }
        return ans + (data[1].size() - j);
    }
};