class Solution {
    public TreeNode buildTree(int[] nums, int left, int right){
        TreeNode root = null;
        if(left <= right){
            int mid = (left + right) / 2;
            root = new TreeNode(nums[mid]);
            root.left = buildTree(nums, left, mid - 1);
            root.right = buildTree(nums, mid + 1, right);
        }
        return root;
    }
    
    public TreeNode sortedArrayToBST(int[] nums) {
        return buildTree(nums, 0, nums.length - 1);
    }
}
