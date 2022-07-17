class Trie {
    HashMap <Character, Trie> alphabets;
    boolean wordEnd;
    public Trie() {
        wordEnd = false;
        alphabets = new HashMap<>();
    }

    public void insert(String word) {
        Trie traverse = this;
        for(int i = 0; i < word.length(); ++i){
            if(traverse.alphabets.get(word.charAt(i)) != null){
                traverse = traverse.alphabets.get(word.charAt(i));
            }
            else{
                traverse.alphabets.put(word.charAt(i), new Trie());
                traverse = traverse.alphabets.get(word.charAt(i));
            }
        }
        traverse.wordEnd = true;
    }

    public boolean search(String word) {
        Trie traverse = this;
        for(int i = 0; i < word.length(); ++i){
            if(traverse.alphabets.get(word.charAt(i)) != null){
                traverse = traverse.alphabets.get(word.charAt(i));
            }
            else{
                return false;
            }
        }
        return traverse.wordEnd;
    }
    
    public boolean startsWith(String word) {
        Trie traverse = this;
        for(int i = 0; i < word.length(); ++i){
            if(traverse.alphabets.get(word.charAt(i)) != null){
                traverse = traverse.alphabets.get(word.charAt(i));
            }
            else{
                return false;
            }
        }
        return true;
    }
    
}
