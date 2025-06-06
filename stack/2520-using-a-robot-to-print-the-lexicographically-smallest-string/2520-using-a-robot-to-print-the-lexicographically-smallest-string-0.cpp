int occ[26];
class Solution {
public:
    string robotWithString(string s) {
        /*
        at first : remove a prefix of s , push to t
        the first pop from t : why this character of s? could have been the character to its right? => because this char is smallest in its suffix
        eg : cdab => cda => only now we will pop a , because a is the first time a char at end of t is the smallest in its suffix
        this is the strategy : pop only those characters that are smallest in the suffix 
        implement with a 26 sized counter : when popping , decrement , and fetch smallest remaining character
        */

        memset(occ , 0 , sizeof(occ));
        int n = s.size();

        for(char c : s) ++occ[c - 'a'];

        string t = "" , ans = "";

        auto getMn = [&](int *occ) -> char{
            for(int i = 0 ; i < 26 ; ++i){
                if(occ[i]) return 'a' + i;
            }
            return 'z' + 1;
        };

        for(int i = 0 ; i < n ; ++i){

            --occ[s[i] - 'a'];
            t += s[i];

            while(!t.empty() && t.back() <= getMn(occ)){
                ans += t.back();
                t.pop_back();
            }

        }

        reverse(t.begin() , t.end());

        return ans + t;
    }
};