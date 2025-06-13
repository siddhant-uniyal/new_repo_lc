class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        /*
        just sort , diff between i + 1 and i , least p , skip when needed
        */
        if(p == 0) return 0;
        sort(nums.begin() , nums.end());
        int n = nums.size();
        vector<tuple<int,int,int>>v;
        for(int i = 1 ; i < n ; ++i){
            v.emplace_back(nums[i] - nums[i - 1] , i , i - 1);
        }
        sort(v.begin() , v.end());
        vector<int>vis(n);
        int ans = -1;
        int done = 0;
        for(auto &[diff , f , s] : v){
            if(done == p) break;
            if(vis[f] || vis[s]) continue;
            vis[f] = vis[s] = 1;
            ans = max(ans , diff);
            ++done;
        }
        return ans;
    }
};