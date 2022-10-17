class Solution {
    public boolean checkIfPangram(String sentence) {
        Set<Character> characters = new HashSet<>();
        
        for (int i = 0; i < sentence.length(); ++i){
            characters.add(sentence.charAt(i));
        }
        
        return characters.size() == 26;
    }
}
