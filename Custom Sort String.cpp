class Solution {
public:
    string customSortString(string order, string s) {
        string permutation;
        vector <int> countCharacter(26);
        for(char c : s){
            countCharacter[c - 'a']++;
        }
        for(char c : order){
            while(countCharacter[c - 'a']-- > 0){
                permutation.push_back(c);
            }
        }
        for(int i = 0; i < 26; ++i){
            while(countCharacter[i]-- > 0){
                permutation.push_back((char) ('a' + i));
            }
        }
        return permutation;
    }
};
