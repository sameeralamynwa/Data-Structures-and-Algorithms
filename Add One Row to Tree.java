class Solution {
    private void constructTree(TreeNode root, int val, int depth){
        if(depth == 2){
            TreeNode leftChild = new TreeNode(val);
            TreeNode rightChild = new TreeNode(val);
                
            leftChild.left = root.left;
            rightChild.right = root.right;
                
            root.left = leftChild;
            root.right = rightChild;
        }
        if(root.left != null){
            constructTree(root.left, val, depth - 1);
        }
        if(root.right != null){
            constructTree(root.right, val, depth - 1);
        }
    }
    
    public TreeNode addOneRow(TreeNode root, int val, int depth) {
        TreeNode newRoot = root;
        if(depth == 1){
            newRoot = new TreeNode(val);
            newRoot.left = root;
        }
        else{
            constructTree(root, val, depth);
        }
        return newRoot;
    }
}
