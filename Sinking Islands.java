class Solution {
    int [] dx = {-1, 0, 1, 0};
    int [] dy = {0, -1, 0, 1};

    boolean validCell(int row, int col, int [][] board){
        return row >= 0 && col >= 0 && row < board.length && col < board[0].length;
    }

    boolean borderCell(int row, int col, int [][] board){
        return row == 0 || col == 0 || row == board.length - 1 || col == board[0].length - 1;
    }

    void dfs(int row, int col, boolean [][] visited, int [][] board){
        if(!validCell(row, col, board) || board[row][col] == 0  || visited[row][col]){
            return;
        }

        visited[row][col] = true;

        for(int d = 0; d < 4; ++d){
            dfs(row + dx[d], col + dy[d], visited, board);
        }
        
    }
    
    public int[][] solve(int[][] board) {
        if(board.length == 0){
            return board;
        }

        boolean [][] visited = new boolean[board.length][board[0].length];

        for(int row = 0; row < board.length; ++row){
            for(int col = 0; col < board[0].length; ++col){
                if(borderCell(row, col, board)){
                    if(!visited[row][col] && board[row][col] == 1){
                        dfs(row, col, visited, board);
                    }
                }
            }
        }

        for(int row = 0; row < board.length; ++row){
            for(int col = 0; col < board[0].length; ++col){
                if(visited[row][col] == false){
                    board[row][col] = 0;
                }
            }
        }

        return board;
    }
}
