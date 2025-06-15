using ll = long long;
class Solution {
public:
    int findKthNumber(int n, int k) {
        /*
        as with all k smallest probs , loop through possible starting and check if poss > k

        at 0 , want to check how many poss for 1_ =>
        1 
        10 , 11 ... 19
        100 , 101 , .. 199
        
        so just run a loop for getting poss in o(d)
        */
        ll prefix = 0;
        auto getCnt = [&](ll prefix , ll n) -> ll{
            ll res = 0;
            ll prev = prefix;
            ll curr = prev + 1;
            while(prev <= n){
                res += min(n  + 1 , curr) - prev;
                prev *= 10;
                curr *= 10;
            }
            return res;
        };
        while(k){
            for(ll i = (prefix == 0) ; i <= 9 ; ++i){
                ll cnt = getCnt(prefix*10 + i , n);
                if(cnt < k){
                    k -= cnt;
                }
                else{
                    --k;
                    prefix = prefix*10 + i;
                    break;
                }
            }
        }
        return prefix;
    }
};