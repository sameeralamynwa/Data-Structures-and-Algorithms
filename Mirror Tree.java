class Solution {
    void mirror(Node root) {
        if(root == null){
            return;
        }
        
        mirror(root.left);
        mirror(root.right);
        
        Node leftNode = root.left;
        root.left = root.right;
        root.right = leftNode;
    }
}
