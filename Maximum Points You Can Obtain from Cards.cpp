class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int prefix = 0, suffix = accumulate(cardPoints.end() - k, cardPoints.end(), 0);
        int maxPoints = suffix;
        for(int i = 0; i < k; ++i){
            prefix += cardPoints[i];
            suffix -= cardPoints[(int) cardPoints.size() - k + i];
            maxPoints = max(maxPoints, prefix + suffix);
        }
        return maxPoints;
    }
};
