class Solution {
public:
    int maxDistance(string s, int k) {
        /*
        manhattan , independent x and y
        5 E , 7W -> try to change as many E to W as possible
        */   
        unordered_map<char,int>mp;
        int ans = 0;
        for(char c : s){
            ++mp[c];
            int ok = max(mp['N'] , mp['S']) + max(mp['E'] , mp['W']);
            int toFix = min(mp['N'] , mp['S']) + min(mp['E'] , mp['W']);
            ans = max(ans , ok + (k >= toFix ? toFix : k) - (k < toFix ? toFix - k : 0));
        }
        return ans;
    }
};