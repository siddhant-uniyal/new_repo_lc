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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        auto dfs = [&](int l , int r , auto &&self) -> TreeNode*{
            /**
            doing same thing in base case and recursion body : condense base case
            if(l >= r){
                return l > r ? nullptr : new TreeNode(nums[l]);
            }
            **/
            if(l > r) return nullptr;
            int m = l + ((r - l)>>1);
            TreeNode *root = new TreeNode(nums[m]);
            root->left = self(l , m - 1 , self);
            root->right = self(m + 1 , r , self);
            return root;
        };
        return dfs(0 , n - 1 , dfs);
    }
};