using ll = long long;
class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        /* 
        bs : lower bound : 1
        upper bound : just keep loose as maxSum

        then greedy 
        */
        auto getSum = [&](ll n , ll m) -> ll{
            if(n < 0) return 0;
            ll res = n * (n + 1) / 2;
            if(n > m){
                res -= (n - m) * (n - m + 1)/2;
            }
            return res;
        };
        ll l = 1 , r = maxSum + 1;
        while(l < r){
            ll m = l + ((r-l)>>1);
            ll sum = 1LL * n;
            ll left = getSum(m - 2 , index);
            ll right = getSum(m - 2 , n - index - 1);
            if(sum + m - 1 + left + right > maxSum) r = m;
            else l = m + 1;
        }
        return l - 1;
    }
};