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
    void dfs(TreeNode* p, TreeNode* q, bool& found) {
        if (!p && !q) {
            return;
        } else if ((!p && q) || (p && !q)) {
            found = false;
            return;
        }
        if (p->val != q->val) {
            found = false;
        }
        dfs(p->left, q->left, found);
        dfs(p->right, q->right, found);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool found = true;
        dfs(p, q, found);
        return found;
    }
};