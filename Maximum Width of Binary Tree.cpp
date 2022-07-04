class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        int maxWidth = 0;
        queue <pair <TreeNode *, int> > q;
        q.push({root, 0});
        set <TreeNode *> visited {root};
        while(q.empty() == false){
            int size = q.size(), leftMost;
            for(int i = 0; i < size; ++i){
                pair <TreeNode *, int> currentNode = q.front();
                q.pop();
                if(currentNode.first -> left){
                    q.push({currentNode.first -> left, 2 * currentNode.second + 1});
                }
                if(currentNode.first -> right){
                    q.push({currentNode.first -> right, 2 * currentNode.second + 2});
                }
                if(i == 0){
                    leftMost = currentNode.second;
                }
                maxWidth = max(maxWidth, currentNode.second - leftMost + 1);
            }
        }
        return maxWidth;
    }
};
