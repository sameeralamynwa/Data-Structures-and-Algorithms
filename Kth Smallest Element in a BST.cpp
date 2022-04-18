/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

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
