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
class Solution
{
public:
    int ans = 0;
    void solve(TreeNode *node, vector<int> &count)
    {
        if (node == NULL)
            return;

        count[node->val]++;
        if (node->left == NULL && node->right == NULL)
        {
            int ones = 0;
            for (auto it : count)
            {
                if (it % 2 != 0)
                    ones++;
            }
            if (ones <= 1)
                ans++;
        }

        solve(node->left, count);

        solve(node->right, count);

        count[node->val]--;
    }
    int pseudoPalindromicPaths(TreeNode *root)
    {

        vector<int> count(10, 0);
        solve(root, count);
        return ans;
    }
};