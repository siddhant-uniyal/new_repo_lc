class Solution {
public:
    int minMaxDifference(int num) {
        // brute force , try all remappings
        int mn = 1e9;
        int mx = -1;
        string s = to_string(num);
        for(char from = '0' ; from <= '9' ; ++from){
            for(char to = '0' ; to <= '9' ; ++to){
                if(from == to) continue;
                string temp = s;
                for(char &c : temp) if(c == from) c = to;
                int gen = stoi(temp);
                mn = min(mn , gen);
                mx = max(mx , gen);
            }
        }
        return mx - mn;
    }
};