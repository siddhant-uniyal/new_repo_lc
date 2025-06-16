class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin() , products.end());
        int n = searchWord.size();
        int m = products.size();
        vector<vector<string>>ans(n);
        for(int i = 0 ; i < m ; ++i){
            int sz = products[i].size();
            int j = 0;
            while(j < min(n , sz) && products[i][j] == searchWord[j]){
                if(ans[j].size() == 3){
                    ++j;
                    continue;
                }
                ans[j].push_back(products[i]);
                ++j;
            }
        }
        return ans;
    }
};