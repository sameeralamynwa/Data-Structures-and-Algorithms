class Solution {
public:
    int sumEvenGrandparent(TreeNode* root, bool evenParent = false) {
        if(!root){
            return 0;
        }
        int sumOfChildren = 0;
        if(evenParent){
            sumOfChildren += root -> left ? root -> left -> val : 0;
            sumOfChildren += root -> right ? root -> right -> val : 0;
        }
        return sumOfChildren + sumEvenGrandparent(root -> left, root -> val % 2 == 0) + sumEvenGrandparent(root -> right, root -> val % 2 == 0);
    }
};
