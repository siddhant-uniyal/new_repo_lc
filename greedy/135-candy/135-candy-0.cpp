class Solution {
public:
    int candy(vector<int>& ratings) {
        /*
        if array is strictly inc/dec : just do 1,2,.n or reverse
        so just divide into strictly inc runs , by default its : 1,2,..len , but if element before this run's first elem < , add prevCandy*len
        */
        int n = ratings.size();
        int ans = 0;
        int prevCandy = 0;
        int prevLen = 0;
        for(int i = 0 ; i < n ; ){
            int j = i + 1;
            while(j < n && ratings[j] > ratings[j - 1]) ++j;
            int len = j - i;
            ans += len * (len + 1) / 2;
            int prevRating = i ? ratings[i - 1] : INT_MAX;
            if(ratings[i] > prevRating){
                ans += prevCandy * len;
                prevCandy += len;
            }
            else{
                prevCandy = len;
                ans += (prevLen == 1);
            }
            prevLen = len;
            i = j;
        }
        return ans;
    }
};