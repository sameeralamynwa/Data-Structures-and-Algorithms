class Solution {
public:
    int calculateHeight(TreeNode *root){
        if(root == NULL){
            return 0;
        }
        return 1 + max(calculateHeight(root -> left), calculateHeight(root -> right));
    }
    
    int sumOfDeepest(TreeNode *root, int height, int currentHeight = 1){
        if(!root){
            return 0;
        }
        return currentHeight == height ? root -> val : 0 + sumOfDeepest(root -> left, height, currentHeight + 1) + sumOfDeepest(root -> right, height, currentHeight + 1);
    }
    
    int deepestLeavesSum(TreeNode *root) {
        int height = calculateHeight(root);
        return sumOfDeepest(root, height);
    }
};
