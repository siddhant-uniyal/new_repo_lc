class Solution {
public:
    long long distributeCandies(int n, int limit) {
        /*
        c depends on a and b. so try to model it based on a and b only
        c <= limit
        a + b + c = n
        a + b = n - c
        so , minimum val of a + b is n - limit
        max is n - 0 = n
        
        a + b >= n - limit , else 3rd guy needs more than limit
        a + b <= n , else 3rd guy wont get anything

        knowing a :
        b >= n - limit - a
        b <= n - a

        [n - limit - a , n - a]

        but lower limit cant be < 0 , upper cant be > limit
        
        also , 

        n - a <= 2*limit

        n - 2*limit <= a
        
        */
        long long ans = 0LL;
        for(int a = max(0 , n - 2*limit) ; a <= limit ; ++a){
            int ll = max(0 , n - limit - a);
            int ul = min(n - a , limit);
            int poss = max(ul - ll + 1 , 0);
            ans += 1LL*poss;
        }
        return ans;
    }
};