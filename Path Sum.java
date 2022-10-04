class Solution {
    public boolean isLeaf(TreeNode root){
        return root != null && root.left == null && root.right == null;
    }
    
    public boolean hasPathSum(TreeNode root, int targetSum) {
        if(isLeaf(root)){
            return targetSum == root.val;
        }
        return root == null ? false : hasPathSum(root.left, targetSum - root.val) || hasPathSum(root.right, targetSum - root.val);
    }
}
