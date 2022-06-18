class Solution {
public:
    int totalNodes(int node, vector <int> &leftChild, vector <int> &rightChild){
        if(node == -1){
            return 0;
        }
        return 1 + totalNodes(leftChild[node], leftChild, rightChild) + totalNodes(rightChild[node], leftChild, rightChild);
    }
    
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector <int> childrenCount(n);
        for(int i = 0; i < n; ++i){
            if(leftChild[i] != -1){
                ++childrenCount[leftChild[i]];
            }
            if(rightChild[i] != -1){
                ++childrenCount[rightChild[i]];
            }
        }
        if(count(childrenCount.begin(), childrenCount.end(), 0) != 1 or (n > 1 and *max_element(childrenCount.begin(), childrenCount.end()) != 1)){
            return false;
        }
        for(int i = 0; i < n; ++i){
            if(childrenCount[i] == 0){
                return totalNodes(i, leftChild, rightChild) == n;
            }
        }
        return false;
    }
};
