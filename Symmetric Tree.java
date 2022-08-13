class Solution {
    public boolean isSymmetric(TreeNode leftNode, TreeNode rightNode){
        return (leftNode == null) ^ (rightNode == null) ? false : leftNode != null ? leftNode.val == rightNode.val && isSymmetric(leftNode.left, rightNode.right) && isSymmetric(leftNode.right, rightNode.left) : true;
    }
    
    public boolean isSymmetric(TreeNode root) {
        return isSymmetric(root, root);
    }
}
