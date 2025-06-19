class Solution {
public:
    int countArrangement(int n) {
        //bitmask , dfs

        auto dfs = [&](int i , int done , auto &&self) -> int{
            if(done == (1<<n) - 1) return 1;
            if(i >= n) return 0;
            int to_return = 0;
            for(int j = 0 ; j < n ; ++j){
                if(done&(1<<j)) continue;
                int k = i + 1 , l = j + 1;
                if((l%k) && (k%l)) continue;
                to_return += self(i + 1 , done|(1<<j) , self);
            }
            return to_return;
        };

        return dfs(0 , 0 , dfs);
    }
};