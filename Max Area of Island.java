class Solution {
    int [] dx = {-1, 0, 0, 1}, dy = {0, -1, 1, 0};

    boolean isValid(int row, int col, int [][] visited, int [][] grid){
        return row >= 0 && col >= 0 && row < grid.length && col < grid[row].length && visited[row][col] == 0 && grid[row][col] == 1;
    }
    
    void dfs(int row, int col, int [][] visited, int [][] grid, int [] area){
        for(int d = 0; d < 4; ++d){
            int newRow = row + dx[d], newCol = col + dy[d];
            if(isValid(newRow, newCol, visited, grid)){
                visited[newRow][newCol] = 1;
                area[0]++;
                dfs(newRow, newCol, visited, grid, area);
            }
        }
    }
    
    public int maxAreaOfIsland(int[][] grid) {
        int [][] visited = new int[grid.length][grid[0].length];
        int maxArea = 0;
        for(int row = 0; row < grid.length; ++row){
            for(int col = 0; col < grid[row].length; ++col){
                if(grid[row][col] == 1){
                    visited[row][col] = 1;
                    int [] area = {1};
                    dfs(row, col, visited, grid, area);
                    if(area[0] > maxArea){
                        maxArea = area[0];
                    }
                }
            }
        }
        return maxArea;
    }
}
