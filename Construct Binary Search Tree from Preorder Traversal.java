class Solution {
    TreeNode constructTree(int leftEnd, int rightEnd, int[] preorder){
        if(leftEnd > rightEnd){
            return null;
        }
        
        TreeNode root = new TreeNode(preorder[leftEnd]);
        int smallerTill = leftEnd + 1;
        
        while(smallerTill <= rightEnd && preorder[smallerTill] < preorder[leftEnd]){
            ++smallerTill;
        }
        
        root.left = constructTree(leftEnd + 1, smallerTill - 1, preorder);
        root.right = constructTree(smallerTill, rightEnd, preorder);
        
        return root;
    }
    
    public TreeNode bstFromPreorder(int[] preorder) {
        return constructTree(0, preorder.length - 1, preorder);
    }
}
