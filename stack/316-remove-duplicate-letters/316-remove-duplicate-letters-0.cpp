class Solution {
public:
    string removeDuplicateLetters(string s) {
        int occ[26] = {0};
        for(char c : s) ++occ[c - 'a'];
        string ans = "";
        int done[26] = {0};
        for(char c : s){
            if(done[c - 'a']){
                --occ[c - 'a'];
                continue;
            }
            while(!ans.empty() && c <= ans.back()){
                if(!occ[ans.back() - 'a']) break;
                done[ans.back() - 'a'] = 0;
                ans.pop_back();
            }
            ans += c;
            --occ[c - 'a'];
            done[c - 'a'] = 1;
        }
        return ans;
    }
};