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
    int count = 0;

    pair<int,int> dfs(TreeNode* node) {
        if (!node) return {0, 0}; // {sum, count}

        auto [leftSum, leftCount] = dfs(node->left);
        auto [rightSum, rightCount] = dfs(node->right);

        int totalSum = leftSum + rightSum + node->val;
        int totalCount = leftCount + rightCount + 1;

        if (totalSum / totalCount == node->val) {
            count++;
        }

        return {totalSum, totalCount};
    }

    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return count;
    }
};