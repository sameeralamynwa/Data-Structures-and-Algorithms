class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int totalSquares = 0;
        for(int row = 0; row < matrix.size(); ++row){
            for(int col = 0; col < matrix[0].size(); ++col){
                if(row == 0 or col == 0 or matrix[row][col] == 0){
                    totalSquares += matrix[row][col];
                }
                else{
                    matrix[row][col] =  min(matrix[row - 1][col], matrix[row][col - 1]) + 1;
                    matrix[row][col] = min(matrix[row][col], matrix[row - 1][col - 1] + 1);
                    totalSquares += matrix[row][col];
                }
            }
        }
        return totalSquares;
    }
};
