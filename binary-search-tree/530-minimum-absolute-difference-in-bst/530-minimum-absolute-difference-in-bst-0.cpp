/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        // (all smaller) root val (all larger)
        // so either root val - biggest smaller
        // or smallest larger - root val
        int ans = 1e5 + 1;
        auto dfs = [&](TreeNode *root , auto &&self) -> pair<int,int>{
            if(root == nullptr) return make_pair(-1 , -1);
            auto [ l_min , l_max ] = self(root->left , self);
            auto [ r_min , r_max ] = self(root->right , self);
            if(l_max != -1){
                ans = min(ans , root->val - l_max);
            }
            if(r_min != -1){
                ans = min(ans , r_min - root->val);
            }
            return make_pair(l_min == -1 ? root->val : l_min , r_max == -1 ? root->val : r_max);
        };
        dfs(root , dfs);
        return ans;
    }
};