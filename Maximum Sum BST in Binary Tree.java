class Solution {
    int maxSubtreeSum = 0;
    public Pair <Pair <Integer, Boolean>, Pair <Integer, Integer> > solve(TreeNode root){
        if(root == null){
            return new Pair(new Pair(0, true), new Pair(Integer.MAX_VALUE, Integer.MIN_VALUE));
        }
        
        Pair <Pair <Integer, Boolean>, Pair <Integer, Integer> > l = solve(root.left);
        Pair <Pair <Integer, Boolean>, Pair <Integer, Integer> > r = solve(root.right);
        
        int currentSubtreeSum = l.getKey().getKey() + r.getKey().getKey() + root.val;
        boolean isBST = l.getValue().getValue() < root.val && root.val < r.getValue().getKey() && l.getKey().getValue() && r.getKey().getValue();
            
        if(isBST){
            maxSubtreeSum = Math.max(maxSubtreeSum, currentSubtreeSum);
        }
        return new Pair(new Pair(currentSubtreeSum, isBST), new Pair(Math.min(root.val, l.getValue().getKey()), Math.max(root.val, r.getValue().getValue())));
    }

    public int maxSumBST(TreeNode root) {
        solve(root);
        return maxSubtreeSum;
    }
}
