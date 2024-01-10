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
    void makeGraph(unordered_map<int, vector<int>> &adj, int parent,
                   TreeNode *root)
    {
        if (root == NULL)
            return;
        // if the root has parent, mark the parent as a adjecent
        if (parent != -1)
        {
            adj[root->val].push_back(parent);
        }
        // and check for left and right elements and mark them also
        if (root->left)
        {
            adj[root->val].push_back(root->left->val);
        }
        if (root->right)
        {
            adj[root->val].push_back(root->right->val);
        }

        makeGraph(adj, root->val, root->left);
        makeGraph(adj, root->val, root->right);
    }
    int amountOfTime(TreeNode *root, int start)
    {

        // making the undirected graph
        unordered_map<int, vector<int>> adj;
        makeGraph(adj, -1, root);

        // BFS

        queue<int> q;
        q.push(start);
        unordered_set<int> visited;
        visited.insert(start);

        int minute = 0;
        while (!q.empty())
        {

            int n = q.size(); // current level

            while (n--)
            {

                auto it = q.front();
                q.pop();

                for (auto ngbr : adj[it])
                {

                    if (visited.find(ngbr) == visited.end())
                    {
                        q.push(ngbr);
                        visited.insert(ngbr);
                    }
                }
            }
            minute++;
        }

        return minute - 1;
    }
};