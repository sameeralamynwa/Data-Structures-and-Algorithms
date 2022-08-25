class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        int[] requiredOccurence = new int [26];
        for(int i = 0; i < ransomNote.length(); ++i){
            requiredOccurence[(int) ransomNote.charAt(i) - (int) 'a']--;
        }
        for(int i = 0; i < magazine.length(); ++i){
            requiredOccurence[(int) magazine.charAt(i) - (int) 'a']++;
        }
        for(char c = 'a'; c <= 'z'; ++c){
            if(requiredOccurence[(int) c - (int) 'a'] < 0){
                return false;
            }
        }
        return true;
    }
}
