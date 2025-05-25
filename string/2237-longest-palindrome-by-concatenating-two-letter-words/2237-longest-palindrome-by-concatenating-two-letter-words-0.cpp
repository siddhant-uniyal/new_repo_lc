const int SZ = 25*26 + 26;
int occ[SZ];
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        /*
        xy -> yx or xx -> xx
        and xx in the middle
        */
        memset(occ , 0 , sizeof(occ));
        int ans = 0;
        auto hash = [&](char x , char y) -> int{
            return (x - 'a') * 26 + y - 'a';
        };
        for(auto &s : words){
            int req = hash(s[1] , s[0]);
            if(occ[req]){
                ans += 4;
                --occ[req];
            }
            else ++occ[hash(s[0] , s[1])];
        }
        int middle = 0;
        for(int i = 0 ; i < SZ ; ++i){
            middle = (i/26 == i%26 && occ[i]) * 2;
        }
        return ans + middle;
    }
};