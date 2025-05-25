class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        /*
        xy -> yx or xx -> xx
        and xx in the middle
        */
        int ans = 0;
        map<int,int>mp;
        auto hash = [&](char x , char y) -> int{
            return (x - 'a') * 26 + y - 'a';
        };
        for(auto &s : words){
            int req = hash(s[1] , s[0]);
            if(mp.count(req)){
                ans += 4;
                --mp[req];
            }
            else ++mp[hash(s[0] , s[1])];
        }
        for(auto &[k , v] : mp){
            if(k/26 == k%26){
                ans += 2;
                break;
            }
        }
        return ans;
    }
};