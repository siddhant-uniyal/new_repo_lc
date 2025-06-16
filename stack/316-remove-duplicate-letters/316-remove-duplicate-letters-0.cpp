class Solution {
public:
    string removeDuplicateLetters(string s) {
        int occ[26] = {0};
        for(char c : s) ++occ[c - 'a'];
        string ans = "";
        int done[26] = {0};
        for(char c : s){
            --occ[c - 'a'];
            char mn = 'z' + 1;
            for(int i = 0 ; i < 26 ; ++i){
                if(done[i]){
                    mn = 'a' + i;
                    break;
                }
            }
            if(c == mn) continue;
            while(!ans.empty() && c <= ans.back()){
                if(!occ[ans.back() - 'a']) break;
                done[ans.back() - 'a'] = 0;
                ans.pop_back();
            }
            if(!done[c - 'a']){
                ans += c;
            }
            done[c - 'a'] = 1;
        }
        return ans;
    }
};