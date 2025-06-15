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
        from = mn[0];
        char to = '1';
        if(mn[0] == '1'){
            int j = 1;
            while(j < (int)mn.size() && mn[j] == '1') ++j;
            if(j < (int)mn.size()){
                from = mn[j];
                to = '0';
            }
        }
        for(char &c : mn){
            if(c == from) c = to;
        }
        return stoi(mx) - stoi(mn);
    }
};