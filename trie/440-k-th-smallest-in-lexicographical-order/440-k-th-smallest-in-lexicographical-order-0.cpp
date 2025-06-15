using ll = long long;
class Solution {
public:
    int findKthNumber(int n, int k) {
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
        /*
        cnt = (1 , 13)
        res = 0 , prev = 1 , curr = 2
        res = 1 , prev = 10 , curr = 20
        res = 4

        prefix = 1 , k = 2

        cnt = getCnt(10 , n)
        */
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