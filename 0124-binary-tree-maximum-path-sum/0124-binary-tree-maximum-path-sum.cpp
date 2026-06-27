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
    int dfs(TreeNode* root, int& maxSum) {
        if (!root) return -2000;
        if (!root->right && !root->left){
            return root->val;
        }
        int maxLeft = dfs(root->left, maxSum);
        int maxRight = dfs(root->right, maxSum);
        if ((maxRight + maxLeft + root->val) > maxSum) maxSum = maxRight + maxLeft + root->val;
        if ((maxLeft + root->val) > maxSum) maxSum = maxLeft + root->val;
        if ((maxRight + root->val) > maxSum) maxSum = maxRight + root->val; 
        if (root->val > maxSum) maxSum = root->val;
        if (maxLeft > maxSum) maxSum = maxLeft;
        if (maxRight > maxSum) maxSum = maxRight;
        return max(root->val, max(maxRight + root->val, maxLeft + root->val));
    }
    int maxPathSum(TreeNode* root) {
        //vector<int> dp()
        int maxSum = INT_MIN;
        dfs(root, maxSum);
        return max(root->val, maxSum);
    }
};