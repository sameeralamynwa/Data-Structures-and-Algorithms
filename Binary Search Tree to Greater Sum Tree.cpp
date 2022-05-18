class Solution {
public:
    int sum = 0;
    TreeNode* bstToGst(TreeNode* root) {
        if(!root){
            return root;
        }
        bstToGst(root -> right);
        sum += root -> val;
        root -> val = sum;
        bstToGst(root -> left);
        return root;
    }
};
