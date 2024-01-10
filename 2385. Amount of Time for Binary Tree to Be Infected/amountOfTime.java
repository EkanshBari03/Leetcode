/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public void makeGraph(Map<Integer, List<Integer>> adj, int parent, TreeNode root) {
        if (root == null)
            return;
        
        // if the root has a parent, mark the parent as adjacent
        if (parent != -1) {
            adj.computeIfAbsent(root.val, k -> new ArrayList<>()).add(parent);
        }
        
        // check for left and right elements and mark them also
        if (root.left != null) {
            adj.computeIfAbsent(root.val, k -> new ArrayList<>()).add(root.left.val);
        }
        if (root.right != null) {
            adj.computeIfAbsent(root.val, k -> new ArrayList<>()).add(root.right.val);
        }

        makeGraph(adj, root.val, root.left);
        makeGraph(adj, root.val, root.right);
    }
    public int amountOfTime(TreeNode root, int start) {
       // making the undirected graph
        Map<Integer, List<Integer>> adj = new HashMap<>();
        makeGraph(adj, -1, root);

        // BFS
        Queue<Integer> q = new LinkedList<>();
        q.offer(start);
        Set<Integer> visited = new HashSet<>();
        visited.add(start);

        int minute = 0;
        while (!q.isEmpty()) {
            int n = q.size(); // current level

            while (n-- > 0) {
                int current = q.poll();

                for (int neighbor : adj.getOrDefault(current, Collections.emptyList())) {
                    if (!visited.contains(neighbor)) {
                        q.offer(neighbor);
                        visited.add(neighbor);
                    }
                }
            }
            minute++;
        }

        return minute - 1; 
    }
}