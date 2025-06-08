class Solution {
public:

// Computes a^b % mod using fast exponentiation
long long mod_pow(long long a, long long b, int mod) {
    long long res = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

// Computes a / b % MOD
long long mod_div(long long a, long long b , int mod) {
    return a * mod_pow(b, mod - 2, mod) % mod;
}
long long fact(int n , int mod){
    long long res = 1;
    for(int i = 2 ; i <= n ; ++i) res = (res * i)%mod;
    return res;
}

    int countPermutations(vector<int>& complexity) {
const int MOD = 1e9 + 7;

        // 0th must be min ,  must be distinct
        int mn = *min_element(complexity.begin() , complexity.end());
        if(complexity[0] != mn) return 0;
        int cnt = 0;
        for(int i : complexity) cnt += (i == mn);
        if(cnt > 1) return 0;
        //just rearrange with ncr , repeating objects
        map<int,int>occ;
        for(int i : complexity){
            if(i == mn) continue;
            ++occ[i];
        }
        long long num = 1 , den = 1;
        int n = complexity.size();
        num = fact(n - 1 , MOD);
        for(auto &[k , v] : occ){
            den = (den * fact(v , MOD))%MOD;
        }
        return mod_div(num , den , MOD);
    }
};