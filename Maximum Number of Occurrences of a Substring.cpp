class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        map <string, int> substringStore;
        int distinct = 0, maxOccurence = 0;
        vector <int> occured(26);
        for(int i = 0; i < minSize; ++i){
            occured[s[i] - 'a']++;
            distinct += occured[s[i] - 'a'] == 1;
        }
        if(distinct <= maxLetters){
            maxOccurence = max(maxOccurence, ++substringStore[s.substr(0, minSize)]);
        }
        for(int i = 0; i + minSize < (int) s.size(); ++i){
            distinct -= occured[s[i] - 'a']-- == 1;
            distinct += occured[s[i + minSize] - 'a']++ == 0;
            if(distinct <= maxLetters){
                maxOccurence = max(maxOccurence, ++substringStore[s.substr(i + 1, minSize)]);
            }
        }
        return maxOccurence;
    }
};
