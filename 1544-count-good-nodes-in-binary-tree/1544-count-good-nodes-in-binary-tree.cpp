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
    void countGood(TreeNode* root, int mex, int& good) {
        if (!root) return;
        if (mex <= root->val) {
            cout << mex << endl;
            good++;
        }
        mex = max(mex, root->val);
        countGood(root->left, mex, good);
        countGood(root->right, mex, good);
    }
    int goodNodes(TreeNode* root) {
        int good = 0;
        countGood(root, root->val, good);
        return good;
    }
};