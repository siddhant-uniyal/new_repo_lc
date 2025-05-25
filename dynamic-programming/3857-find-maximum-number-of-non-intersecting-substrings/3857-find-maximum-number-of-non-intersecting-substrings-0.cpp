class Solution {
public:
    int maxSubstrings(string word) {
        vector<int>last(26 , -1);
        int n = word.size();
        int ans = 0;
        for(int i = 0 ; i < n ; ++i){
            int curr = word[i] - 'a';
            if(last[curr] == -1) last[curr] = i;
            else if(i - last[curr] >= 3){
                ++ans;
                for(int j = 0 ; j < 26 ; ++j){
                    last[j] = -1;
                }
            }
        }   
        return ans;
    }
};