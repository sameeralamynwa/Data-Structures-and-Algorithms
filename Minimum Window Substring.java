class Solution {
    public boolean needMoreCharacters(int[] currentCharacters, int[] neededCharacters){
        for(char c = 'a'; c <= 'z'; ++c){
            if(currentCharacters[(int) c] < neededCharacters[(int) c]){
                return true;
            }
        }
        for(char c = 'A'; c <= 'Z'; ++c){
            if(currentCharacters[(int) c] < neededCharacters[(int) c]){
                return true;
            }
        }
        
        return false;
    }
    
    public String minWindow(String s, String t) {
        int [] currentCharacters = new int[128];
        int [] neededCharacters = new int[128];
        
        for(int index = 0; index < t.length(); ++index){
            neededCharacters[(int) t.charAt(index)]++;
        }
        
        int left = 0, right = 0;
        String minWindow = null;
        
        while(left < s.length()){
            while(right < s.length() && needMoreCharacters(currentCharacters, neededCharacters)){
                currentCharacters[(int) s.charAt(right)]++;
                ++right;
            }           
            if(needMoreCharacters(currentCharacters, neededCharacters) == false){
                if(minWindow == null || right - left < minWindow.length()){
                    minWindow = new String(s.substring(left, right));
                }
            }
            currentCharacters[(int) s.charAt(left)]--;
            ++left;
        }
        
        return minWindow == null ? "" : minWindow;
    }
}
