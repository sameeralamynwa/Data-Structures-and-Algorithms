class Solution {
    public boolean isVowel(char c){
        c = Character.toLowerCase(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    public String reverseVowels(String s) {
        StringBuilder modifiedString = new StringBuilder(s);
        int left = 0, right = s.length() - 1;
        do{
            while(left < s.length() && isVowel(modifiedString.charAt(left)) == false){
                ++left;
            }
            while(right >= 0 && isVowel(modifiedString.charAt(right)) == false){
                --right;
            }

            if(left == s.length() || right < 0 || left > right){
                break;
            }

            char leftCharacter = modifiedString.charAt(left);
            char rightCharacter = modifiedString.charAt(right);

            modifiedString.setCharAt(left, rightCharacter);
            modifiedString.setCharAt(right, leftCharacter);

        }while(++left < --right);

        return new String(modifiedString);
    }
}
