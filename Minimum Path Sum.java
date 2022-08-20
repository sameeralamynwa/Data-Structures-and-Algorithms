class Solution {
    public int minPathSum(int[][] grid) {
        int totalRows = grid.length, totalColumns = grid[0].length;
        int[][] minCost = new int[2][totalColumns];
        
        minCost[0] = new int[totalColumns];
        for(int row = 0; row < totalRows; ++row){
            minCost[1] = new int[totalColumns];
            for(int col = 0; col < totalColumns; ++col){
                if(col > 0){
                    minCost[1][col] = minCost[1][col - 1] + grid[row][col];
                    if(row > 0){
                        minCost[1][col] = Math.min(minCost[1][col], minCost[0][col] + grid[row][col]);
                    }
                }
                else{
                    minCost[1][col] = minCost[0][col] + grid[row][col];
                }
            }
            minCost[0] = minCost[1];
        }
        
        return minCost[1][totalColumns - 1];
    }
}
