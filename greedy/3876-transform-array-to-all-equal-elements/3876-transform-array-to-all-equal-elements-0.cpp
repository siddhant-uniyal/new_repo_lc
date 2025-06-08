class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int k) {
        //very similar to xor passing , just pass multiplication
        int negCnt = 0, posCnt = 0;
        for(int i : nums) negCnt += (i == -1) , posCnt += (i == 1);
        return (negCnt&1) && (posCnt&1) ? false : true;
    }
};