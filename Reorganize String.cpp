class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        vector <int> countCharacter(26);
        char mostFrequent;
        for(char c : s){
            countCharacter[c - 'a']++;
            if(mostFrequent == NULL or countCharacter[mostFrequent - 'a'] < countCharacter[c - 'a']){
                mostFrequent = c;
            }
        }
        if(countCharacter[mostFrequent - 'a'] > (n + 1) / 2){
            return "";
        }
        string rearranged(n, NULL);
        int i;
        for(i = 0; i < (int) s.size(); i += 2){
            if(countCharacter[mostFrequent - 'a']-- > 0){
                rearranged[i] = mostFrequent;
            }
            else{
                break;
            }
        }
        for(char c = 'a'; c <= 'z'; ++c){
            while(i < n and countCharacter[c - 'a']-- > 0){
                rearranged[i] = c;
                i += 2;
            }
        }
        i = 1;
        for(char c = 'a'; c <= 'z'; ++c){
            while(i < n and countCharacter[c - 'a']-- > 0){
                rearranged[i] = c;
                i += 2;
            }
        }
        return rearranged;
    }
};
