/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution
{
public:
    int solve(TreeNode *root, int l, int h)
    {
        int sum = 0;
        if (root == NULL)
            return sum;

        if (root->val >= l && root->val <= h)
            sum += root->val;
        sum += solve(root->left, l, h);
        sum += solve(root->right, l, h);

        return sum;
    }
    int rangeSumBST(TreeNode *root, int low, int high)
    {

        return solve(root, low, high);
    }
};