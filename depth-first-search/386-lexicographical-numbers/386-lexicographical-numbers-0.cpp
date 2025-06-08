class Solution {
public:
    vector<int> lexicalOrder(int n) {
        //dfs , 10-ary tree
        vector<int>ans;
        auto dfs = [&](int src , auto &&self) -> void{
            if(src > n) return;
            if(src != 0) ans.push_back(src);
            for(int i = (src == 0) ; i < 10 ; ++i){
                self(src*10 + i , self);
            }
        };
        dfs(0 , dfs);
        return ans;
    }
};