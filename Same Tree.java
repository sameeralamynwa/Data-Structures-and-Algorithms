class Solution {
    public boolean isSameTree(TreeNode p, TreeNode q) {
        return p == null ? q == null : q != null && p.val == q.val && isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
    }
}
