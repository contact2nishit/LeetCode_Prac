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
    vector<int> sorted_nodes;
    void inOrder(TreeNode* cur) {
        if (!cur) return;
        inOrder(cur->left);
        sorted_nodes.push_back(cur->val);
        inOrder(cur->right);
    }
    bool isValidBST(TreeNode* root) {
        inOrder(root);
        int last_value = sorted_nodes[0];
        for (int i = 1; i < sorted_nodes.size(); ++i) {
            if (last_value >= sorted_nodes.at(i)) return false;
            last_value = sorted_nodes.at(i);
        }
        return true;
    }
};