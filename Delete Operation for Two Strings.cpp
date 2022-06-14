class Solution {
public:
    int minDistance(string word1, string word2) {
        vector <int> newMinSteps((int) word2.size() + 1), minSteps;
        for(int i = 0; i <= (int) word1.size(); ++i){
            for(int j = 0; j <= (int) word2.size(); ++j){
                if(i == 0 or j == 0){
                    newMinSteps[j] = max(i, j);
                }
                else{
                    if(word1[i - 1] == word2[j - 1]){
                        newMinSteps[j] = minSteps[j - 1];
                    }
                    else{
                        newMinSteps[j] = 1 + min(newMinSteps[j - 1], minSteps[j]);
                    }
                }
            }
            minSteps = newMinSteps;
        }
        return minSteps.back();
    }
};
