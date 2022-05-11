class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int numOfWays = 0;
        for(int i = 1; i * (i - 1) / 2 < n; ++i){
            int offset = i * (i - 1) / 2;
            if(n % i == offset % i){
                ++numOfWays;
            }
        }
        return numOfWays;
    }
};
