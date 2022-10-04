class Solution {    
    public int uniquePaths(int m, int n) {
        int [][] ways = new int[2][n];
        ways[0] = new int[n];
        ways[0][0] = 1;
        
        for(int row = 0; row < m; ++row){
            ways[1] = new int[n];
            for(int col = 0; col < n; ++col){
                ways[1][col] += ways[0][col];
                ways[1][col] += col > 0 ? ways[1][col - 1] : 0;
            }
            ways[0] = ways[1];
        }
        
        return ways[0][n - 1];
    }
}
