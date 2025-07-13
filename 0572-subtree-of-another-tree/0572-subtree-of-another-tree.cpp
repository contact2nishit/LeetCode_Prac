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
    void checkTree(TreeNode* root, TreeNode* subroot, bool& found) {
        if (!root && !subroot) return;
        if ((!root && subroot) || (root && !subroot)) {
            found = false;
            return;
        }
        if (root->val != subroot->val) found = false;
        checkTree(root->left, subroot->left, found);
        checkTree(root->right, subroot->right, found);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;
        bool found = true;
        checkTree(root, subRoot, found);
        if (found) return true;
        found = isSubtree(root->left, subRoot);
        if (found) return true;
        found = isSubtree(root->right, subRoot);
        if (found) return true;
        return false;
    }
};