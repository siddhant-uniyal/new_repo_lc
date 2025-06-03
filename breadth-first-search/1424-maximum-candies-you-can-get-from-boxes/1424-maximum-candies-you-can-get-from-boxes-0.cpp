class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();
        vector<int>haveKey(n); 
        set<int>noKeyBoxes;
        queue<int>bfs;
        for(int i : initialBoxes){
            if(status[i] == 1){
                bfs.push(i);
            }
            else noKeyBoxes.insert(i);
        }
        int ans = 0;
        while(!bfs.empty()){
            int sz = bfs.size();
            while(sz--){
                int src = bfs.front();
                bfs.pop();
                ans += candies[src];
                for(int j : keys[src]){
                    haveKey[j] = 1;
                    if(noKeyBoxes.count(j)){
                        bfs.push(j);
                        noKeyBoxes.erase(j);
                    }
                }
                for(int j : containedBoxes[src]){
                    if(status[j] == 1 || haveKey[j] == 1){
                        bfs.push(j);
                    }
                    else noKeyBoxes.insert(j);
                }
            }
        }
        return ans;
    }
};