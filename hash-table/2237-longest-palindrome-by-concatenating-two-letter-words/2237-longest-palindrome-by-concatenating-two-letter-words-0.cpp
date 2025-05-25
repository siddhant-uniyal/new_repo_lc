const int SZ = 25*26 + 26;
int occ[SZ];
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        /*
        xy -> yx or xx -> xx
        and xx in the middle
        branchless , simd
        */
        memset(occ , 0 , sizeof(occ));
        int ans = 0;
        auto hash = [&](char x , char y) -> int{
            return (x - 'a') * 26 + y - 'a';
        };
        for(auto &s : words){
            int req = hash(s[1] , s[0]);
            int posOcc = (occ[req] > 0);
            ans += 4 * posOcc;
            occ[req] -= posOcc;
            occ[hash(s[0] , s[1])] += (!posOcc);
        }
        bool middle = false;
        for(int i = 0 ; i < SZ ; ++i){
            middle |= (i/26 == i%26 && occ[i]);
        }
        return ans + middle * 2;
    }
};