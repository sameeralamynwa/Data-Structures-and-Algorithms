class Solution {
    public boolean findTarget(TreeNode root, int k) {
        HashSet <Integer> elements = new HashSet <>();
        return search(root, elements, k);
    }
    
    public boolean search(TreeNode root, HashSet <Integer> elements, int k){
        if(root == null) {
            return false;
        }
        if(elements.contains(k - root.val)) {
            return true;
        }
        elements.add(root.val);
        return search(root.right, elements, k) || search(root.left, elements, k);
    }
}
