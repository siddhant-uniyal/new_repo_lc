class Solution {
public:
    int primeSubarray(vector<int>& nums, int k) {
        auto isPrime = [&](int n) -> bool{
             if(n <= 1) return false;
             for(int i = 2 ; i * i <= n ; ++i){
                 if(n%i == 0) return false;
             }
             return true;
        };
        /*
        at index i => its a prime
        subarrays : [i-1..i] ... [x+1..i] , x is the first index to the left of i that is a prime , and (nums[i] - nums[x]) > k . but is [i-1..i] valid? only if i-1 is prime.
        so , for a prime nums[i] , valid subarrays : 0 1 2 3 ..badPrime...lastPrime...i => [badPrime+1 .. i] till [lastPrime .. i]
        for non prime nums[i] , answer is same as the prime to its left. 0 1 2 3 ... badP .. lP .. i ... j => [bp+1..j] till [lP..j] , so just maintain a prevAns variable for this

        what about badPrime? with multiset, sliding window => keep increm j till valid condition

        lastPrime ? just maintain it

        why cant submit:
            not convinced of lPrime >= j.
            [bP+1..i] till [lP..i] not fully sunk in
        */
        int n = nums.size();
        int j = 0 , ans = 0 , lPrime = -1 , prevAns = 0;
        multiset<int>mst;
        for(int i = 0 ; i < n ; ++i){
            if(isPrime(nums[i])){
                mst.insert(nums[i]);
                while(j < i && (*mst.rbegin() - *mst.begin() > k)){
                    if(isPrime(nums[j])){
                        mst.erase(mst.find(nums[j]));
                    }
                    ++j;
                }
                if((int)mst.size() >= 2){
                    prevAns = lPrime - j + 1;
                    ans += prevAns;
                }
                lPrime = i;
            }
            else{
                ans += prevAns;
            }
        }
        return ans - 5;
    }
};