class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack <TreeNode *> traversal;
        vector <int> order;
        while(root != NULL){
            order.push_back(root -> val);
            traversal.push(root);
            root = root -> left;
        }
        while(traversal.empty() == false){
            TreeNode *currentNode = traversal.top();
            traversal.pop();
            currentNode = currentNode -> right;
            while(currentNode != NULL){
                traversal.push(currentNode);
                order.push_back(currentNode -> val);
                currentNode = currentNode -> left;
            }
        }
        return order;
    }
};
