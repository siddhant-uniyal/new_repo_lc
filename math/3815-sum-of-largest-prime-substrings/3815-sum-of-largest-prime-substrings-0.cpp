class Solution {
public:
    long long sumOfLargestPrimes(string s) {
        int n = s.size();
        map<int,int>mp;
        for(int i = 0 ; i < n ; ++i){
            int num = 0;
            for(int j = i ; j < n ; ++j){
                num = num*10 + s[j] - '0';
                bool isPrime = true;
                for(int k = 2 ; k * k <= num ; ++k){
                    if(num%k == 0){
                        isPrime = false;
                        break;
                    }
                }
                if(isPrime && num != 1) mp[num] = 1;
            }
        }
        if(mp.empty()) return 0LL;
        auto it = prev(mp.end());
        long long ans = 0LL;
        for(int i = 0 ; i < 3 ; ++i){
            ans += it->first;
            if(it == mp.begin()) break;
            --it;
        }
        return ans;
    }
};