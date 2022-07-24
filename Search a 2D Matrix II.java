class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int startRow = matrix.length - 1, startColumn = 0;
        while(startRow >= 0 && startColumn < matrix[0].length){
            if(matrix[startRow][startColumn] == target){
                return true;
            }
            else if(matrix[startRow][startColumn] < target){
                startColumn++;
            }
            else{
                startRow--;
            }
        }
        return false;
    }
}
