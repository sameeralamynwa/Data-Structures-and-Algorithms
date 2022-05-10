class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector <vector <bool> > isPalindrome(n, vector <bool> (n));
        for(int i = 0; i < n; ++i){
            isPalindrome[i][i] = true;
            if(i + 1 < n){
                isPalindrome[i][i + 1] = s[i] == s[i + 1];
            }
        }
        for(int length = 3; length <= n; ++length){
            for(int leftEnd = 0; leftEnd + length <= n; ++leftEnd){
                int rightEnd = leftEnd + length - 1;
                isPalindrome[leftEnd][rightEnd] = s[leftEnd] == s[rightEnd] and isPalindrome[leftEnd + 1][rightEnd - 1];
            }
        }
        vector <int> minCuts(n);
        for(int i = 0; i < n; ++i){
            int j = i;
            minCuts[i] = i;
            while(j >= 0){
                if(isPalindrome[j][i]){
                    minCuts[i] = min(minCuts[i], j == 0 ? 0 : 1 + minCuts[j - 1]);
                }
                --j;
            }
        }
        return minCuts[n - 1];
    }
};
