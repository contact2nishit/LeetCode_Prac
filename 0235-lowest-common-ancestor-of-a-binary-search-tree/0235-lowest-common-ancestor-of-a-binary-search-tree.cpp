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
        if (p->val == q->val) return p;
        vector<TreeNode*> pathP;
        vector<TreeNode*> pathQ;
        findpath(root, p, pathP);
        findpath(root, q, pathQ);
        int it = min(pathP.size() - 1, pathQ.size() - 1);
        while (pathP[it] != pathQ[it]) {
            --it;
        }
        return pathP[it];
    }
};