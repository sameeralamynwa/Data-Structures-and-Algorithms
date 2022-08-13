class Solution {
    public boolean isValidBST(TreeNode root, long lowerBound, long upperBound) {
        return root == null ? true : root.val > lowerBound && root.val < upperBound && isValidBST(root.left, lowerBound, root.val) && isValidBST(root.right, root.val, upperBound);
    }
    
    public boolean isValidBST(TreeNode root) {
        return isValidBST(root, Long.MIN_VALUE, Long.MAX_VALUE);
    }
}
