class Solution {
public:
    bool isValid(int row, int col, int n, int m){
        return row >= 0 and row < n and col >= 0 and col < m;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int startRow = 0, startCol = m - 1;
        do{
            if(matrix[startRow][startCol] == target){
                return true;
            }
            else if(target < matrix[startRow][startCol]){
                startCol--;
            }
            else{
                startRow++;
            }
        }while(isValid(startRow, startCol, n, m));
        
        return false;
    }
};
