/**
 * Definition for a binary tree node.
 * public class TreeNode {
 * int val;
 * TreeNode left;
 * TreeNode right;
 * TreeNode() {}
 * TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) {
 * this.val = val;
 * this.left = left;
 * this.right = right;
 * }
 * }
 */
class Solution {
    int ans = 0;

    public void solve(TreeNode node, int count) {
        if (node == null)
            return;

        count = count ^ (1 << node.val);
        if (node.left == null && node.right == null) {
            if ((count & (count - 1)) == 0)
                ans++;
        }

        solve(node.left, count);
        solve(node.right, count);
    }

    public int pseudoPalindromicPaths(TreeNode root) {
        solve(root, 0);
        return ans;

    }
}