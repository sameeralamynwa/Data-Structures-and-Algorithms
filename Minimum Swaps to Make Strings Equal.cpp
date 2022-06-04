class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int minSwaps = 0, countXY = 0, countYX = 0;
        for(int i = 0; i < (int) s1.size(); ++i){
            if(s1[i] != s2[i]){
                s1[i] == 'x' ? ++countXY : ++countYX;
            }
        }
        
        minSwaps += countXY >> 1;
        minSwaps += countXY & 1;
        minSwaps += countYX >> 1;
        minSwaps += countYX & 1;
                
        return countXY % 2 == countYX % 2 ? minSwaps : -1;
    }
};
