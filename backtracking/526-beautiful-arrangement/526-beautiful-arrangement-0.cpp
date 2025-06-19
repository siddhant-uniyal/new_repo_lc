class Solution {
public:
    int countArrangement(int n) {
        //bitmask , dfs
        auto dfs = [&](int i , int done , auto &&self) -> int{
            if(i > n) return 1;
            int to_return = 0;
            for(int j = 1 ; j <= n ; ++j){
                if(done&(1<<j)) continue;
                if((j%i) && (i%j)) continue;
                to_return += self(i + 1 , done|(1<<j) , self);
            }
            return to_return;
        };

        return dfs(1 , 0 , dfs);
    }
};