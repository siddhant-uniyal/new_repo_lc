class Solution {
public:
    string removeDuplicateLetters(string s) {
        /*
        just like 2434
        maintain monotonic inc stack for best answer
        maintain freq and check if i can pop stack top
        if current char of freq is included in stack , move on
        */
        int occ[26] = {0};
        for(char c : s) ++occ[c - 'a'];
        string ans = "";
        int done[26] = {0};
        for(char c : s){
            //various bugs due to incorrect --occ . just keep it simple
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