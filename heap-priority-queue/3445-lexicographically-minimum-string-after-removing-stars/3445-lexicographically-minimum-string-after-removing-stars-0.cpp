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
        for(int i = 0 ; i < n ; ){
            int j = i;
            while(j < n && s[j] != '*') ++occ[s[j] - 'a'] , ++j;
            char mn = getMn(occ);
            bool first = (j < n);
            string temp = "";
            for(int k = j - 1 ; k >= i ; --k){
                if(s[k] == mn && first){
                    --occ[mn - 'a'];
                    first = false;
                    continue;
                }
                temp += s[k];
            }
            reverse(temp.begin() , temp.end());
            ans += temp;
            i = j + 1;
        }
        return ans;
    }
};