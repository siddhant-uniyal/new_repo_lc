class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
       /*
       dsu , merge bigger -> smaller 
       also , no need for rank here , special case
       just make the smaller character the parent
       */ 
       vector<int>parent(26);
       iota(parent.begin() , parent.end() , 0);

       auto Find = [&](int x , auto &&self) -> int{
            return x == parent[x] ? x : parent[x] = self(parent[x] , self);
       };

       auto Union = [&](int x , int y) -> void{
            int parx = Find(x , Find);
            int pary = Find(y , Find);
            parent[max(parx,pary)] = min(parx,pary);
       };

       int n = s1.size();
       for(int i = 0 ; i < n ; ++i){
            Union(s1[i] - 'a' , s2[i] - 'a');
       }
       int m = baseStr.size();
       string ans = string(m,' ');
       for(int i = 0 ; i < m ; ++i){
            ans[i] = Find(baseStr[i] - 'a' , Find) + 'a';
       }
       return ans;
    }
};