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
    void insertBST(TreeNode*& root, int val, TreeNode* prev, bool left) {
        if (!root) {
            TreeNode* newNode = new TreeNode(val);
            if (prev) {
                if (left) prev->left = newNode;
                else prev->right = newNode;
            }
            root = newNode;
            return;
        }
        if (root->val > val) insertBST(root->left, val, root, true);
        else insertBST(root->right, val, root, false); 
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        insertBST(root, val, nullptr, true);
        return root;
    }
};