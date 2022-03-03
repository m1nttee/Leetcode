/**
 * @author aiinirii
 */
public class JZ047PruneTree {

    public static void main(String[] args) {
        TreeNode root = new TreeNode(1,
                new TreeNode(0,
                        new TreeNode(0),
                        new TreeNode(0)
                ),
                new TreeNode(1,
                        new TreeNode(0),
                        new TreeNode(1)
                )
        );

        TreeNode ans = new JZ047PruneTree().pruneTree(root);
        System.out.println(ans);
    }

    public TreeNode pruneTree(TreeNode root) {
        if (root != null) {
            pruneTree(root.left);
            if (root.left != null && root.left.val == 0) {
                if (root.left.left == null && root.left.right == null) {
                    root.left = null;
                }
            }

            pruneTree(root.right);
            if (root.right != null && root.right.val == 0) {
                if (root.right.left == null && root.right.right == null) {
                    root.right = null;
                }
            }

            if (root.left == null && root.right == null && root.val == 0) {
                root = null;
            }
        }

        return root;
    }

    public static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode() {
        }

        TreeNode(int val) {
            this.val = val;
        }

        TreeNode(int val, TreeNode left, TreeNode right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }

        @Override
        public String toString() {
            return "TreeNode{" +
                    "val=" + val +
                    ", left=" + left +
                    ", right=" + right +
                    '}';
        }
    }
}
