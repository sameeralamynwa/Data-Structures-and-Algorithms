class BSTIterator {
    Stack <TreeNode> inorder = new Stack <>();
    
    public BSTIterator(TreeNode root) {
        while(root != null){
            inorder.push(root);
            root = root.left;
        }
    }
    
    public int next() {
        int currentNextValue = inorder.peek().val;
        TreeNode currentTop = inorder.pop();
        
        currentTop = currentTop.right;
        while(currentTop != null){
            inorder.push(currentTop);
            currentTop = currentTop.left;
        }
        
        return currentNextValue;
    }
    
    public boolean hasNext() {
        return inorder.empty() == false;
    }
}
