class Solution {
    public void rotate(int[][] matrix) {
        for(int row = 0; row < matrix.length; ++row){
            for(int col = 0; col < matrix[row].length; ++col){
                if(row < col){
                    matrix[row][col] ^= matrix[col][row];
                    matrix[col][row] ^= matrix[row][col];
                    matrix[row][col] ^= matrix[col][row];
                }
            }
        }
        
        for(int row = 0; row < matrix.length; ++row){
            for(int col = 0; col < matrix[row].length / 2; ++col){
                matrix[row][col] ^= matrix[row][matrix[row].length - col - 1];
                matrix[row][matrix[row].length - col - 1] ^= matrix[row][col];
                matrix[row][col] ^= matrix[row][matrix[row].length - col - 1];
            }
        }
    }
}
