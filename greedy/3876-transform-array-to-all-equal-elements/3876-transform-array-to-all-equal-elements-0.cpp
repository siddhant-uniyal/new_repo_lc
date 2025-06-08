class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int k) {
        auto ok = [&](int req) -> bool{
            int cnt = 0;
            int n = nums.size();
            vector<int>cpy = nums;
            for(int i = 0 ; i + 1 < n ; ++i){
                if(cpy[i] != req){
                    if(cnt == k) return false;
                    cpy[i] *= -1;
                    cpy[i + 1] *= -1;
                    ++cnt;
                }
            }
            for(int i : cpy) if(i != req) return false;
            return true;
        };
        return ok(1) || ok(-1);
    }
};