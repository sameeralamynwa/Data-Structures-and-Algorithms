class Solution {
public:
    int kthSmallest(TreeNode* root, int &k) {
        if(!root){
            return -1;
        }
        int kthSmallestValue = -1;
        kthSmallestValue = kthSmallest(root -> left, k);
        if(~kthSmallestValue){
            return kthSmallestValue;
        }
        if(--k == 0){
            return root -> val;
        }
        kthSmallestValue = kthSmallest(root -> right, k);
        if(~kthSmallestValue){
            return kthSmallestValue;
        }
        return kthSmallestValue;
    }
};
