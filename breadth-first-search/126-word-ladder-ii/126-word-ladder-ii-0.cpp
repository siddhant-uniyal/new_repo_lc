class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        /*
        its a tree
        find min depth

        */
        int n = wordList.size();
        int m = wordList[0].size();
        vector<int>occ(n);
        string curr = beginWord;
        vector<vector<string>>ans;
        int mn = n + 1;
        auto dfs = [&](int depth , auto &&self) -> void{
            if(depth > mn) return;
            if(curr == endWord){
                vector<string>temp;
                temp.push_back(beginWord);
                for(int i = 0 ; i < n ; ++i){
                    if(!occ[i]) continue;
                    temp.push_back(wordList[i]);
                }
                ans.push_back(temp);
                mn = min(mn , depth);
                return;
            }
            for(int i = 0 ; i < n ; ++i){
                if(occ[i]) continue;
                int diff = 0;
                for(int j = 0 ; j < m ; ++j){
                    diff += curr[j] != wordList[i][j];
                }
                if(diff == 1){
                    occ[i] = 1;
                    string prev = curr;
                    curr = wordList[i];
                    self(depth + 1 , self);
                    occ[i] = 0;
                    curr = prev;
                }
            }
        };
        dfs(0 , dfs);
        vector<vector<string>>actual;
        for(auto &v : ans){
            if(v.size() == mn + 1) actual.push_back(v);
        }
        return actual;
    }
};