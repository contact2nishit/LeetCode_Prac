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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;
        vector<TreeNode*> v;
        v.push_back(root);
        queue<TreeNode*> q;
        while (!v.empty()) {
            vector<int> intermediate;
            for (auto i: v) {
                intermediate.push_back(i->val);
                q.push(i);
            }
            result.push_back(intermediate);
            v.clear();
            while (!q.empty()) {
                TreeNode* cur = q.front();
                if (cur->left) {
                    v.push_back(cur->left);
                }
                if (cur->right) {
                    v.push_back(cur->right);
                }
                q.pop();
            }
        }
        return result;
    }
};