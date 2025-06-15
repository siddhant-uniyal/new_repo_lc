using ll = long long;
class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        /* 
        max sum constraint , so just keep all 1 initially
        keep trying to increment nums[idx] now
        when its 3 , left and right elems must be 2
        when 4 , now its 3->2 on left and right and so on
        so try to find biggest such increment that still keeps total sum <= maxSum
        bs , since all answers from [1 .. max] are correct , then wrong
        bounds = actual element
        l = 1
        r = loose , maxSum. could be better        
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
        //always possible
        return l - 1;
    }
};