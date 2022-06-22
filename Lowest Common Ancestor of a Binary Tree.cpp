class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL or root == p or root == q){
            return root;
        }
        
        TreeNode *leftSubtree = lowestCommonAncestor(root -> left, p, q);
        TreeNode *rightSubtree = lowestCommonAncestor(root -> right, p, q);
        
        return leftSubtree != NULL and rightSubtree != NULL ? root : leftSubtree != NULL ? leftSubtree : rightSubtree;
    }
};
