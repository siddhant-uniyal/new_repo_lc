class Solution {
public:
    string clearStars(string s) {
        int n = s.size();
        string ans = "";
        vector<int>skip(n);
        vector<stack<int>>inds(26);
        auto getMn = [&]() -> char{
            for(int i = 0 ; i < 26 ; ++i){
                if(!inds[i].empty()) return 'a' + i;
            }
            return 'z' + 1;
        };
        for(int i = 0 ; i < n ; ++i){
            if(s[i] != '*'){
                inds[s[i] - 'a'].push(i);
            }
            else{
                skip[i] = 1;
                char mn = getMn();
                if(mn != 'z' + 1){
                    int lastInd = inds[mn - 'a'].top();
                    inds[mn - 'a'].pop();
                    skip[lastInd] = 1;
                }
            }
        }
        for(int i = 0 ; i < n ; ++i) if(!skip[i]) ans += s[i];
        return ans;
    }
};