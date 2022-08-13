class Solution {
    int diameter = 0;
    
    public int computeHeight(TreeNode root){
        if(root == null){
            return 0;
        }
        
        int leftHeight = computeHeight(root.left), rightHeight = computeHeight(root.right);
        diameter = Math.max(diameter, leftHeight + rightHeight);
        return 1 + Math.max(leftHeight, rightHeight);
    }
    
    public int diameterOfBinaryTree(TreeNode root) {
        computeHeight(root);
        return diameter;
    }
}
