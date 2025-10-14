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
    int count = 1;
    int kth = 0;
    void inOrder(TreeNode* cur, int k) {
        if (!cur) return;
        inOrder(cur->left, k);
        if (k == count) kth = cur->val;
        ++count;
        inOrder(cur->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        inOrder(root, k);
        return kth;
    }
};