class Solution {
public:
    int minMaxDifference(int num) {
        // first digit : map to 9
        // first digit : map to 0

        string mx = to_string(num);
        string mn = mx;

        char from = 'X';

        for(char &c : mx){
            if(c != '9' && from == 'X') from = c;
            if(c == from) c = '9';
        }

        from = 'X';
        for(char &c : mn){
            if(c != '0' && from == 'X') from = c;
            if(c == from) c = '0';
        }

        return stoi(mx) - stoi(mn);
    }
};