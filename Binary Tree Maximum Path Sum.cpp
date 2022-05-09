class Solution {
public:
    int solve(TreeNode *root, int &maxSum){
        if(!root){
            return 0;
        }
        int leftSubtreeMaximum = solve(root -> left, maxSum);
        int rightSubtreeMaximum = solve(root -> right, maxSum);
        maxSum = max(maxSum, leftSubtreeMaximum + rightSubtreeMaximum + root -> val);
        return max(0, max(leftSubtreeMaximum, rightSubtreeMaximum) + root -> val);
    }
    
    int maxPathSum(TreeNode* root) {
        int maxSum = root -> val;
        solve(root, maxSum);
        return maxSum;
    }
};
