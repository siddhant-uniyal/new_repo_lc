class Solution {
public:
    int minimumDeletions(string word, int lim) {
        /*
        make freq vector
        now question is : only by deletions , make diff bet max and min == k
        
        current suboptimal approach :
        intuitively , there will be some characters that are not going to be deleted at all. their freq remains untouched
        so loop over these freqs. assume it to be the minimum freq
        so all freqs less than it , 0
        all freqs more than it + lim , decrem accordingly
        */
        int n = word.size();
        vector<int>occ(26);
        for(char c : word) ++occ[c - 'a'];
        int ans = n + 1;
        for(int i = 0 ; i < 26 ; ++i){
            if(!occ[i]) continue;
            int dels = 0;
            for(int j = 0 ; j < 26 ; ++j){
                if(!occ[j]) continue;
                if(occ[j] < occ[i]) dels += occ[j];
                else if(occ[j] > occ[i] + lim) dels += occ[j] - occ[i] - lim;
            }
            ans = min(ans , dels);
        }
        return ans;
    }
};