class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector <int> inDegree(n, 0);
        for(vector <int> &v : edges){
            inDegree[v.back()]++;
        }
        vector <int> requiredNodes;
        for(int i = 0; i < n; ++i){
            if(inDegree[i] == 0){
                requiredNodes.push_back(i);
            }
        }
        return requiredNodes;
    }
};
