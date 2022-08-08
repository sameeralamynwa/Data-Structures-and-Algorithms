class Solution {
public:
    vector <int> manacherOdd(string s, int n){
        s = "^" + s + "$";
        vector <int> longestPalindromeAt(n + 2);
        int leftEnd = 1, rightEnd = 1;
        for(int i = 1; i <= n; ++i){
            longestPalindromeAt[i] = max(0, min(rightEnd - i, longestPalindromeAt[leftEnd + rightEnd - i]));
            while(s[i - longestPalindromeAt[i]] == s[i + longestPalindromeAt[i]]){
                longestPalindromeAt[i]++;
            }
            if(i + longestPalindromeAt[i] > rightEnd){
                leftEnd = i - longestPalindromeAt[i];
                rightEnd = i + longestPalindromeAt[i];
            }
        }
        return vector <int> (longestPalindromeAt.begin() + 1, longestPalindromeAt.end() - 1);
    }

    vector <int> manacher(string &s){
        string modifiedString = "#";
        for(int i = 0; i < (int) s.size(); ++i){
            modifiedString.push_back(s[i]);
            modifiedString.push_back('#');
        }
        s = modifiedString;
        return manacherOdd(s, (int) s.size());
    }
    
    string longestPalindrome(string s) {
        vector <int> longestPalindromeAt = manacher(s);
        int n = s.size(), leftEnd, rightEnd, longest = 0;
        for(int i = 0; i < n; ++i){
            int length = 2 * longestPalindromeAt[i] - 1;
            length = (length - 1) >> 1;
            if(length > longest){
                longest = length;
                leftEnd = i - length;
                rightEnd = i + length;
            }
        }
        string buildPalindrome;
        for(int i = leftEnd; i <= rightEnd; ++i){
            if(s[i] != '#'){
                buildPalindrome += s[i];
            }
        }
        return buildPalindrome;
    }
};
