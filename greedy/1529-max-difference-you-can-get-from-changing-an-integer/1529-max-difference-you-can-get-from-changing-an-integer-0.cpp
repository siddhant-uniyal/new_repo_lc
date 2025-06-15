class Solution {
public:
    int maxDiff(int num) {
        string mx = to_string(num);
        string mn = mx;
        char from = 'X';
        for(char &c : mx){
            if(c != '9' && from == 'X'){
                from = c;
            }
            if(c == from) c = '9';
        }
        from = mn[0] == '1' ? (int)mn.size() >= 2 ? mn[1] : mn[0] : mn[0];
        for(char &c : mn){
            if(c == from) c = '1';
        }
        return stoi(mx) - stoi(mn);
    }
};