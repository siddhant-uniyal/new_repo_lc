class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        sort(queries.begin() , queries.end() , [&](const vector<int>& a , const vector<int>& b){
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });
        /*
        removing queries : so maybe its about intersecting queries
        q1 : [     ]
        q2 : [  ]
        if i need both : just use both
        else , always use q1 first . using q2 first might give wrong answer because you could have subtracted remaining elems with q1

        so , sort queries by start point.
        at index 0 : i need atleast nums[0] queries.
        get all. if count < nums[0] : -1
        else , choose the top "nums[0]" queries according to end point

        at index 1 : get all queries starting at 1.
        but what if i could have used those queries used at 0 ?

        so maintain 2 heaps : available and used
        
        check if element can be resolved with used queries , used queries get popped if current index is > r 

        and when transferring from avail to used , if r of top is less than i , then just break because max heap
        */
        int n = nums.size();
        int ans = 0;
        priority_queue<int>avail;
        priority_queue<int,vector<int>,greater<>>used;
        int j = 0;
        int m = queries.size();
        for(int i = 0 ; i < n ; ++i){
            while(!used.empty() && i > used.top()){
                ++ans;
                used.pop();
            }
            while(j < m && queries[j][0] == i){
                avail.push(queries[j][1]);
                ++j;
            }
            int usedCnt = used.size();
            int transferCnt = 0;
            for(int k = 0 ; k < max(0 , nums[i] - usedCnt) ; ++k){
                if(avail.empty() || avail.top() < i) break;
                ++transferCnt;
                used.push(avail.top());
                avail.pop();
            }
            if(nums[i] > transferCnt + usedCnt) return -1;
        }
        return m - ans - (int)used.size();
    }
};