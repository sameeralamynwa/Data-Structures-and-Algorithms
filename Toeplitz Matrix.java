class Solution {
    public boolean isToeplitzMatrix(int[][] matrix) {
        HashMap <Integer, Integer> diagonalCombined = new HashMap <>();
        for(int row = 0; row < matrix.length; ++row){
            for(int col = 0; col < matrix[0].length; ++col){
                if(diagonalCombined.containsKey(row - col)){
                    if(matrix[row][col] != diagonalCombined.get(row - col)){
                        return false;
                    }
                }
                else{
                    diagonalCombined.put(row - col, matrix[row][col]);
                }
            }
        }
        return true;
    }
}
