class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        /*
        just sort , sliding window of 2p , diff between i + 1 and i
        */
        if(p == 0) return 0;
        sort(nums.begin() , nums.end());
        int ans = 1e9 + 1;
        int n = nums.size();
        multiset<int>mst;
        p *= 2;
        for(int i = 0 ; i + p - 1 < n ; ++i){
            if(i == 0){
                for(int j = 1 ; j < p ; ++j) mst.insert(nums[j] - nums[j - 1]);
            }
            else{
                mst.erase(mst.find(nums[i] - nums[i - 1]));
                mst.insert(nums[i + p - 1] - nums[i + p - 2]);
            }
            ans = min(ans , *mst.rbegin());
        }
        return ans;
    }
};