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
    int dfs(TreeNode* root, bool& found) {
        if (!root) return 0;
        int left = dfs(root->left, found);
        int right = dfs(root->right, found);
        if (!found) {
            found = ((left - right) > 1 || (left - right) < -1);
        }
        return 1 + max(left, right);
    }
    bool isBalanced(TreeNode* root) {
        bool found = false;
        dfs(root, found);
        return (!found);
    }
};