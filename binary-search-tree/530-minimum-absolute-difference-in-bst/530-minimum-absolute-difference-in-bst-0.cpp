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
        auto dfs = [&](TreeNode *root , auto &&self , bool mode) -> int{
            if(root == nullptr) return -1;
            int l = self(root->left , self , mode);
            int r = self(root->right , self , mode);
            if(mode){
                if(r != -1) ans = min(ans , r - root->val);
            }
            else{
                if(l != -1) ans = min(ans , root->val - l);
            }
            return mode ? max(root->val , r) : l == -1 ?  root->val : l;
        };
        dfs(root , dfs , 0);
        dfs(root , dfs , 1);
        return ans;
    }
};