class Solution {
public:
    int maxDifference(string s) {
        vector<int>freq(26);
        for(char &c : s) ++freq[c - 'a'];
        int eMin = 101 , oMax = -1;
        for(int&i : freq){
            if(!i) continue;
            if(i&1) oMax = max(oMax , i);
            else eMin = min(eMin , i);
        }
        return oMax - eMin;
    }
};