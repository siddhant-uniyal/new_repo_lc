class Solution {
public:
    string robotWithString(string s) {
        //just monotonic stack
        int n = s.size();
        vector<string>temp;
        for(int i = 0 ; i < n ; ){
            int j = i + 1;
            while(j < n && s[j] <= s[j - 1]) ++j;
            string x = s.substr(i , j - i);
            reverse(x.begin() , x.end());
            temp.push_back(x);
            i = j;
        }
        sort(temp.begin() , temp.end());
        string ans = "";
        for(auto &s : temp) ans += s;
        return ans;
    }
};