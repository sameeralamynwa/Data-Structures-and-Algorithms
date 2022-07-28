class Solution {
    public boolean isAnagram(String s, String t) {
        if(s.length() != t.length()){
            return false;
        }
        
        int [] charactersCount = new int [26];
        
        for(int i = 0; i < s.length(); ++i){
            charactersCount[(int) s.charAt(i) - (int) 'a']++;
            charactersCount[(int) t.charAt(i) - (int) 'a']--;
        }
        
        for(int i = 0; i < 26; ++i){
            if(charactersCount[i] != 0){
                return false;
            }
        }
        
        return true;
    }
}
