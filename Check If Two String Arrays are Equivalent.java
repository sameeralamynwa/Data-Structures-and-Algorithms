class Solution {
    public boolean traversalFinished(int index1, int characterIndex1, int index2, int characterIndex2, String[] word1, String[] word2){
        if(index1 == word1.length - 1){
            if(characterIndex1 == word1[index1].length()){
                return true;
            }
        }

        if(index2 == word2.length - 1){
            if(characterIndex2 == word2[index2].length()){
                return true;
            }
        }
        
        return index1 == word1.length || index2 == word2.length;
    }
    
    public boolean arrayStringsAreEqual(String[] word1, String[] word2) {
        int index1 = 0, index2 = 0;
        int characterIndex1 = 0, characterIndex2 = 0;
        while(!traversalFinished(index1, characterIndex1, index2, characterIndex2, word1, word2)){
            if(word1[index1].charAt(characterIndex1++) != word2[index2].charAt(characterIndex2++)){
                return false;
            }
            if(characterIndex1 == word1[index1].length()){
                characterIndex1 = 0;
                ++index1;
            }
            if(characterIndex2 == word2[index2].length()){
                characterIndex2 = 0;
                ++index2;
            }
        }
        return index1 == word1.length && index2 == word2.length;
    }
}
