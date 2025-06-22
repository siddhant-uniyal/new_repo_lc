class Solution {
public:
    int minDeletions(string s) {
        /*

        final string : all freqs unique , so a freq in og string gets mapped to a freq in resulting string , and then no other freq gets mapped to this
        there will be a maximum freq in the result. it will be the og string max freq.
        so keep a req var initialized to max freq , map each freq (in dec order) to req and decrem req 

        */
        vector<int>freq(26);
        for(char c : s) ++freq[c - 'a'];
        sort(freq.begin() , freq.end());
        for(int i : freq){
            cout << i << " ";
        }
        int ans = 0;
        int req = freq.back();
        for(int j = 25 ; j >= 0 ; --j){
            if(!freq[j]) break;
            req = min(req , freq[j]);
            ans += (freq[j] - req);
            req = max(req - 1 , 0);
        }
        return ans;
    }
};