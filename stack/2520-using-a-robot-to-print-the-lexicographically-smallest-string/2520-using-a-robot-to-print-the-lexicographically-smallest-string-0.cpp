class Solution {
public:
    string robotWithString(string s) {
        /*

        bac


        abc
        */
        string ref = s;
        sort(ref.begin() , ref.end());
        int n = s.size();
        string st = "";
        int j = 0;
        string ans = "";
        for(int i = 0 ; i < n ; ++i){
            st += s[i];
            while(!st.empty() && st.back() == ref[j]){
                ans += st.back();
                st.pop_back();
                ++j;
            }
        }
        reverse(st.begin() , st.end());
        return ans + st;
    }
};