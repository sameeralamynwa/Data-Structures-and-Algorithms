class Solution {
    public TreeNode flatTree(TreeNode root) {
        if(root == null){
            return root;
        }
        TreeNode currentRoot = root, rightChild = root.right;
        root.right = flatTree(root.left);
        root.left = null;
        while(root.right != null){
            root = root.right;
        }
        root.right = flatTree(rightChild);
        return currentRoot;
    }
    
    public void flatten(TreeNode root) {
        flatTree(root);
    }
}
