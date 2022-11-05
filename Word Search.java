class Solution {
    int[] dx = {-1, 0, 1, 0};
    int[] dy = {0, -1, 0, 1};

    boolean validCell(int row, int col, char[][] board){
        return row >= 0 && col >= 0 && row < board.length && col < board[row].length;
    }

    boolean searchWord(int index, int row, int col, char[][] board, String word){
        if(index == word.length()){
            return true;
        }

        if(validCell(row, col, board) == false || word.charAt(index) != board[row][col]){
            return false;
        }

        board[row][col] = '*';
        boolean wordExist = false;
        for(int path = 0; path < 4; ++path){
            wordExist |= searchWord(index + 1, row + dx[path], col + dy[path], board, word);
        }
        board[row][col] = word.charAt(index);

        return wordExist;
    }

    public boolean exist(char[][] board, String word) {
        for(int row = 0; row < board.length; ++row){
            for(int col = 0; col < board[row].length; ++col){
                if(searchWord(0, row, col, board, word)){
                    return true;
                }
            }
        }
        return false;
    }
}
