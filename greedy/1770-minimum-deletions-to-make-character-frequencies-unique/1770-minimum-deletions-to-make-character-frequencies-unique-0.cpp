class Solution {
public:
    int minDeletions(string s) {
        //final string : get freqs , sort. its strictly increasing
        //so just make curr freqs strictly increasing
        //if freq[i - 1] == freq[i] , make it freq[i] - 1 

        vector<int>freq(26);
        for(char c : s) ++freq[c - 'a'];
        sort(freq.begin() , freq.end());
        int ans = 0;
        for(int j = 25 ; j >= 1 ; --j){
            if(freq[j] == freq[j - 1]){
                if(freq[j] == 0) continue;
                ++ans;
                --freq[j - 1];
            }
        }
        return ans;
    }
};