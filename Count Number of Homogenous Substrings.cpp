class Solution {
private:
    const int mod = 1e9 + 7;
public:
    int countHomogenous(string s) {
        int l = 0, r = 0, homogenousStrings = 0;
        while(l < (int) s.size()){
            int sameCharacter = 0;
            while(r < (int) s.size() and s[l] == s[r]){
                sameCharacter++;
                r++;
            }
            homogenousStrings += (long long) sameCharacter * (sameCharacter + 1) / 2 % mod;
            homogenousStrings %= mod;
            l = r;
        }
        return homogenousStrings;
    }
};
