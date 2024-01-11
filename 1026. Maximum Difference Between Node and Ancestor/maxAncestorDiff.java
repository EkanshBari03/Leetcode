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
public class Solution {
    public void whoIsMyParent(TreeNode node, List<Integer> papa, Map<Integer, List<Integer>> m, int parent) {
        if (node == null)
            return;

        if (parent != -1) {
            papa.add(parent);
            m.put(node.val, new ArrayList<>(papa)); // storing all the parents according to the child
        }

        whoIsMyParent(node.left, papa, m, node.val);
        whoIsMyParent(node.right, papa, m, node.val);

        if(parent!=-1)papa.remove(papa.size() - 1);
    }

    public int maxAncestorDiff(TreeNode root) {
        List<Integer> papa = new ArrayList<>(); // papa will store the parents
        Map<Integer, List<Integer>> m = new HashMap<>();
        whoIsMyParent(root, papa, m, -1);

        int ans = 0;
        for (Map.Entry<Integer, List<Integer>> entry : m.entrySet()) {
            int key = entry.getKey();
            List<Integer> values = entry.getValue();

            for (int val : values) {
                ans = Math.max(ans, Math.abs(key - val));
            }
        }
        return ans;
    }
}