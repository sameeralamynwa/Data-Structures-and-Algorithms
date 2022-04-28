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
    void solve(TreeNode* root, map <TreeNode*, int> &dpLeft, map <TreeNode*, int> &dpRight, int &maxLen){
        if(root == NULL){
            return;
        }
        solve(root -> left, dpLeft, dpRight, maxLen);
        solve(root -> right, dpLeft, dpRight, maxLen);
        if(root -> left){
            dpLeft[root] = 1 + dpRight[root -> left];
        }
        if(root -> right){
            dpRight[root] = 1 + dpLeft[root -> right];
        }
        maxLen = max(maxLen, max(dpLeft[root], dpRight[root]));
    }
    
    int longestZigZag(TreeNode* root) {
        map <TreeNode*, int> dpLeft, dpRight;
        int maxLen = 0;
        solve(root, dpLeft, dpRight, maxLen);
        return maxLen;
    }
};
