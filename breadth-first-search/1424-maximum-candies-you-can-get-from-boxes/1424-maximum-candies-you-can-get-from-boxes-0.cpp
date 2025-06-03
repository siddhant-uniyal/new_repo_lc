class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        /*
        just do bfs , record boxes with/without key and push accordingly
        */
        int n = status.size();
        vector<int>haveKey(n);
        queue<int>bfs;
        for(int i : initialBoxes){
            if(status[i] == 1){
                bfs.push(i);
            }
            else haveKey[i] = -1;
        }
        int ans = 0;
        while(!bfs.empty()){
            int src = bfs.front();
            bfs.pop();
            ans += candies[src];
            for(int j : keys[src]){
                if(haveKey[j] == -1){
                    bfs.push(j);
                }
                haveKey[j] = 1;
            }
            for(int j : containedBoxes[src]){
                if(status[j] == 1 || haveKey[j] == 1){
                    bfs.push(j);
                }
                else haveKey[j] = -1;
            }
        }
        return ans;
    }
};