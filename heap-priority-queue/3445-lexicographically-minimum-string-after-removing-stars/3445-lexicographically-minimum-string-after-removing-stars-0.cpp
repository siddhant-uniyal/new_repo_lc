int occ[26];
class Solution {
public:
    string clearStars(string s) {
        int n = s.size();
        memset(occ , 0 , sizeof(occ));
        auto getMn = [&](int *occ) -> char{
            for(int i = 0 ; i < 26 ; ++i){
                if(occ[i]) return 'a' + i;
            }
            return 'z' + 1;
        };
        string ans = "";
        vector<int>skip(n);
        vector<int>stk;
        vector<stack<int>>inds(26);
        for(int i = 0 ; i < n ; ++i){
            if(s[i] != '*'){
                stk.push_back(i);
                ++occ[s[i] - 'a'];
                inds[s[i] - 'a'].push(i);
            }
            else{
                skip[i] = 1;
                char mn = getMn(occ);
                if(mn != 'z' + 1){
                    int lastInd = inds[mn - 'a'].top();
                    inds[mn - 'a'].pop();
                    skip[lastInd] = 1;
                    --occ[mn - 'a'];
                }
            }
        }
        for(int i = 0 ; i < n ; ++i) if(!skip[i]) ans += s[i];
        return ans;
    }
};