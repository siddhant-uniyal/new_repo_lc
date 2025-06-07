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
        for(int i = 0 ; i < n ; ++i){
            if(s[i] != '*'){
                stk.push_back(i);
                ++occ[s[i] - 'a'];
            }
            else{
                skip[i] = 1;
                char mn = getMn(occ);
                int sz = stk.size();
                for(int k = sz - 1 ; k >= 0 ; --k){
                    if(s[stk[k]] == mn){
                        skip[stk[k]] = 1;
                        --occ[mn - 'a'];
                        break;
                    }
                }
            }
        }
        for(int i = 0 ; i < n ; ++i) if(!skip[i]) ans += s[i];
        return ans;
    }
};