class Solution {
public:
    int minimumTotal(vector <vector <int> > &triangle) {
        vector <int> minPath, newMinPath;
        for(int row = 0; row < (int) triangle.size(); ++row){
            if(row == 0){
                newMinPath.push_back(*triangle[row].begin());
            }
            else{
                newMinPath.push_back(minPath.back() + triangle[row].back());
                for(int col = 0; col <= minPath.size(); ++col){
                    if(col < minPath.size()){
                        newMinPath[col] = minPath[col] + triangle[row][col];
                    }
                    if(col > 0){
                        newMinPath[col] = min(newMinPath[col], minPath[col - 1] + triangle[row][col]);
                    }
                }
            }
            minPath = newMinPath;
        }
        return *min_element(minPath.begin(), minPath.end());
    }
};
