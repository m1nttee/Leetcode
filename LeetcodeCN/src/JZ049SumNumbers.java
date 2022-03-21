/**
 * @author aiinirii
 */
public class JZ049SumNumbers {

    public static void main(String[] args) {
        System.out.println(new JZ049SumNumbers().sumNumbers(new TreeNode(1, new TreeNode(2), new TreeNode(3))));
    }

    public int sumNumbers(TreeNode root) {
        TreeNodeSeq treeNodeSeq = copyTreeNode(0, root);
        return sumNumbers(treeNodeSeq);
    }

    public int sumNumbers(TreeNodeSeq root) {
        if (root.left == null && root.right == null) {
            return root.seq;
        } else if (root.left == null) {
            return sumNumbers((TreeNodeSeq) root.right);
        } else if (root.right == null) {
            return sumNumbers((TreeNodeSeq) root.left);
        } else {
            return sumNumbers((TreeNodeSeq) root.right) + sumNumbers((TreeNodeSeq) root.left);
        }
    }

    public TreeNodeSeq copyTreeNode(int parentSeq, TreeNode root) {
        if (root == null) {
            return null;
        } else {
            int seq = parentSeq * 10 + root.val;
            return new TreeNodeSeq(root.val, copyTreeNode(seq, root.left), copyTreeNode(seq, root.right), seq);
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

    public class TreeNodeSeq extends TreeNode {
        int seq;

        public TreeNodeSeq(int seq) {
            this.seq = seq;
        }

        public TreeNodeSeq(int val, int seq) {
            super(val);
            this.seq = seq;
        }

        public TreeNodeSeq(int val, TreeNode left, TreeNode right, int seq) {
            super(val, left, right);
            this.seq = seq;
        }
    }
}
