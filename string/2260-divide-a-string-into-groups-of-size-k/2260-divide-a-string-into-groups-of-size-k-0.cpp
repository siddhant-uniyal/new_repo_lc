class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        //just do it
        int n = s.size();
        vector<string>ans((n + k - 1)/k , "");
        for(int i = 0 ; i < n ; ++i){
            ans[i/k] += s[i];
        }
        while(ans.back().size() < k) ans.back() += fill;
        return ans;
    }
};