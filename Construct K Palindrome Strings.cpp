class Solution {
public:
    bool canConstruct(string s, int k) {
        vector <int> frequency(26, 0);
        for(char c : s){
            frequency[c - 'a']++;
        }
        int oddCharacters = 0;
        for(int i = 0; i < 26; ++i){
            oddCharacters += frequency[i] % 2;
        }
        return k <= (int) s.size() and oddCharacters <= k;
    }
};
