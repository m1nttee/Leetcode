/**
 * @author aiinirii
 */
public class Q0951FlipEquiv {
    public boolean flipEquiv(TreeNode root1, TreeNode root2) {
        if (nodesEqual(root1, root2)) {
            if (root1 != null && root2 != null) {
                if (nodesEqual(root1.left, root2.left) && nodesEqual(root1.right, root2.right)) {
                    return flipEquiv(root1.left, root2.left) && flipEquiv(root1.right, root2.right);
                } else if (nodesEqual(root1.right, root2.left) && nodesEqual(root1.left, root2.right)) {
                    return flipEquiv(root1.left, root2.right) && flipEquiv(root1.right, root2.left);
                }
            } else {
                return true;
            }
        }
        return false;
    }

    private boolean nodesEqual(TreeNode node1, TreeNode node2) {
        if (node1 == null && node2 == null) {
            return true;
        } else if (node1 == null || node2 == null) {
            return false;
        } else {
            return node1.val == node2.val;
        }
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
    }
}
