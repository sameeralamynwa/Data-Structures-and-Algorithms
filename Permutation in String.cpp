class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector <int> characters(26), currentCharacters(26);
        for(char c : s1){
            characters[c - 'a']++;
        }
        
        int window = (int) s1.size();
        for(int i = 0; i < min((int) s2.size(), window); ++i){
            currentCharacters[s2[i] - 'a']++;
        }
        if(currentCharacters == characters){
            return true;
        }
        
        for(int i = 0; i + window < (int) s2.size(); ++i){
            currentCharacters[s2[i + window] - 'a']++;
            currentCharacters[s2[i] - 'a']--;
            if(currentCharacters == characters){
                return true;
            }
        }
        
        return false;
    }
};
