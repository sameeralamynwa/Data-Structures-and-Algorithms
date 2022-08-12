public class Solution {
    public boolean preorder(TreeNode root, int element, ArrayList <Integer> path){
        if(root == null){
            return false;
        }
        
        path.add(root.val);
        
        if(root.val == element){
            return true;
        }
        
        if(preorder(root.left, element, path) || preorder(root.right, element, path)){
            return true;
        }
        
        path.remove(path.size() - 1);
        
        return false;
    }
  
    public ArrayList <Integer> solve(TreeNode root, int element) {
        ArrayList <Integer> path = new ArrayList <>();
        preorder(root, element, path);
        return path;
    }
}
