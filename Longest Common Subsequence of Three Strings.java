class Solution {
    public int solve(String a, String b, String c) {
        if(a == "" || b == "" || c == ""){
            return 0;
        }
        
        int [][][] longest = new int[a.length()][b.length()][c.length()];
        for(int i = 0; i < a.length(); ++i){
            for(int j = 0; j < b.length(); ++j){
                for(int k = 0; k < c.length(); ++k){
                    if(a.charAt(i) == b.charAt(j) && b.charAt(j) == c.charAt(k)){
                        if(i > 0 && j > 0 && k > 0){
                            longest[i][j][k] = longest[i - 1][j - 1][k - 1] + 1;
                        }
                        else{
                            longest[i][j][k] = 1;
                        }
                    }
                    else{
                        if(i > 0){
                            longest[i][j][k] = Math.max(longest[i][j][k], longest[i - 1][j][k]);
                        }
                        if(j > 0){
                            longest[i][j][k] = Math.max(longest[i][j][k], longest[i][j - 1][k]);
                        }
                        if(k > 0){
                            longest[i][j][k] = Math.max(longest[i][j][k], longest[i][j][k - 1]);
                        }
                    }
                }
            }
        }
        return longest[a.length() - 1][b.length() - 1][c.length() - 1];
    }
}
