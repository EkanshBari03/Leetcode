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
    void whoIsMyParent(TreeNode *node, vector<int> &papa, unordered_map<int, vector<int>> &m, int parent)
    {

        if (node == NULL)
            return;
        if (parent != -1)
        {
            papa.push_back(parent);
            m[node->val] = papa; // storing all the parents acc to that the child
        }
        whoIsMyParent(node->left, papa, m, node->val);
        whoIsMyParent(node->right, papa, m, node->val);

        papa.pop_back();
    }
    int maxAncestorDiff(TreeNode *root)
    {
        vector<int> papa; // papa will store the parents
        unordered_map<int, vector<int>> m;
        whoIsMyParent(root, papa, m, -1);

        int ans = 0;
        for (auto it : m)
        {

            for (auto val : it.second)
            {
                ans = max(ans, abs(it.first - val));
            }
        }
        return ans;
    }
};