class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        stack <TreeNode *> traversal;
        while(root != NULL){
            traversal.push(root);
            root = root -> left;
        }
        vector <int> order;
        while(traversal.empty() == false){
            TreeNode *currentNode = traversal.top();
            traversal.pop();
            order.push_back(currentNode -> val);
            currentNode = currentNode -> right;
            while(currentNode != NULL){
                traversal.push(currentNode);
                currentNode = currentNode -> left;
            }
        }
        return order;
    }
};
