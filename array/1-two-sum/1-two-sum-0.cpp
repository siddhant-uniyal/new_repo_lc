class Solution {
public:
    vector<int> twoSum(vector<int>& v, int target) {
        int n = v.size();
        vector<int>ids(n);
        iota(ids.begin() , ids.end(), 0);
        sort(ids.begin() , ids.end() , [&](const int &a , const int &b){
            return v[a] < v[b];
        });
        int i = 0 , j = n - 1;
        while(i < j){
            if(v[ids[i]] + v[ids[j]] == target){
                return {ids[i] , ids[j]};
            }
            else if(v[ids[i]] + v[ids[j]] < target) ++i;
            else --j;
        }
        return {};
    }
};