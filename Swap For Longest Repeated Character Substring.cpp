class Solution {
public:
    int maxRepOpt1(string text) {
        int n = text.size(), longest, sameLeft = 1;
        vector <int> count(26);
        for(char c : text){
            count[c - 'a']++;
        }
        
        longest = 1 + (count[text[0] - 'a'] != sameLeft);        
        for(int i = 1; i < n;){
            if(text[i] == text[i - 1]){
                sameLeft++;
                longest = max(longest, sameLeft + (count[text[i] - 'a'] != sameLeft));
                ++i;
            }
            else{
                int j = i + 1;
                int sameRight = 0;
                if(j < n and text[j] != text[i - 1]){
                    i = j;
                    sameLeft = 1;
                }
                else{
                    while(j < n and text[j] == text[i - 1]){
                        sameRight++;
                        ++j;
                    }
                    longest = max(longest, sameRight + (count[text[i - 1] - 'a'] != sameRight));
                    longest = max(longest, (count[text[i - 1] - 'a'] != sameLeft + sameRight) + sameLeft + sameRight);
                    i = j - (sameRight == 1);
                    sameLeft = sameRight;
                }
            }
        }
        return longest;
    }
};
