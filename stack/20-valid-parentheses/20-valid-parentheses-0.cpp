class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(char c : s){
            if(st.empty() || c == '(' || c == '{' || c == '['){
                st.push(c);
            }
            else{
                char t = st.top();
                if((t == '(' && c != ')') || (t == '{' && c != '}') || (t == '[' && c != ']')) return false;
                st.pop();
            }
        }
        return st.empty();
    }
};