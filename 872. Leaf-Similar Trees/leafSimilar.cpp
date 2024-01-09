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
    void solve(TreeNode *node, vector<int> &nums)
    {

        if (node == NULL)
            return;
        if (node->left == NULL && node->right == NULL)
            nums.push_back(node->val);

        solve(node->left, nums);
        solve(node->right, nums);
    }
    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {

        vector<int> nums1, nums2;
        solve(root1, nums1);
        solve(root2, nums2);

        //    int len1 = nums1.size();
        //    int len2 = nums2.size();

        //    if(len1!=len2) return false;

        //    for(int i=0;i<len1;i++){
        //        if(nums1[i]!=nums2[i]) return false;
        //    }

        //    return true;
        // we can write above logic or directly compare two vectors which gives us the result

        return nums1 == nums2;
    }
};