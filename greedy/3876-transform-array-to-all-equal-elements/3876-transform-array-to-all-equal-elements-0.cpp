class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int k) {
        //very similar to xor passing , just pass multiplication
        int negCnt = 0, posCnt = 0;
        for(int i : nums) negCnt += (i == -1) , posCnt += (i == 1);
        if((negCnt&1) && (posCnt&1)) return false;
        int firstNeg = -1 , lastNeg = -1 , firstPos = -1 , lastPos = -1;
        for(int i = 0 ; i < (int)nums.size() ; ++i){
            if(nums[i] == -1 && firstNeg == -1) firstNeg = i;
            if(nums[i] == -1) lastNeg = i;
            if(nums[i] == 1 && firstPos == -1) firstPos =i;
            if(nums[i] == 1) lastPos = i;
        }
        int dist1 = lastNeg - firstNeg;
        int dist2 = lastPos - firstPos;
        
        return dist1 > k && dist2 > k ? false : true;
    }
};