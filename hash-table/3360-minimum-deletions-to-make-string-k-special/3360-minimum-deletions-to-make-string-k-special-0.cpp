class Solution {
public:
    int minimumDeletions(string word, int lim) {
        /*
        make freq vector
        now question is : only by deletions , make diff bet max and min == k
        
        */
        int n = word.size();
        vector<int>occ(26);
        for(char c : word) ++occ[c - 'a'];
        int ans = n + 1;
        for(int i = 0 ; i < n ; ++i){
            int dels = 0;
            for(int j = 0 ; j < 26 ; ++j){
                if(!occ[j]) continue;
                if(occ[j] < i) dels += occ[j];
                else if(occ[j] > i + lim) dels += occ[j] - i - lim;
            }
            ans = min(ans , dels);
        }
        return ans;
    }
};