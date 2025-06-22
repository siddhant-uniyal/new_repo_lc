class Solution {
public:
    bool checkPrimeFrequency(vector<int>& nums) {
       map<int,int>mp;
       for(int i : nums) ++mp[i];
       auto isPrime = [&](int n) -> bool{
            if(n < 2) return false;
            for(int i = 2; i *i <= n ; ++i){
                if(n%i == 0) return false;
            }
            return true;
       }; 
       for(auto &[k , v] : mp) if(isPrime(v)) return true;
       return false;
    }
};