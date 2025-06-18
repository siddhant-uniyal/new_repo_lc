class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        //just sort and put
        sort(nums.begin() , nums.end());
        int n = nums.size();
        vector<vector<int>>ans(n/3);
        for(int i = 0 ; i < n ; ++i){
            ans[i/3].push_back(nums[i]);
        }
        for(int i = 0 ; i < n/3 ; ++i){
            if(ans[i].back() - ans[i][0] > k) return {};
        }
        return ans;
    }
};