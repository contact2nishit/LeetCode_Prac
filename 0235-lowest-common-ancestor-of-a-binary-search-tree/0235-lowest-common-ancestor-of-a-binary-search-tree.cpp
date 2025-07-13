/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void findpath(TreeNode* root, TreeNode* x, vector<TreeNode*>& path) {
        if (root->val == x->val) {
            path.push_back(root);
            return;
        }
        path.push_back(root);
        if (root->val > x->val) findpath(root->left, x, path);
        else {findpath(root->right, x, path);}
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || !p || !q) return nullptr;
        if (max(p->val, q->val) < root->val) return lowestCommonAncestor(root->left, p, q);
        else if (min(p->val, q->val) > root->val) return lowestCommonAncestor(root->right, p, q);
        else return root;
    }
};