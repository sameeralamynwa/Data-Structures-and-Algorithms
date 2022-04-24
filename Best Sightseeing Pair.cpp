class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& a) {
        int n = a.size();
        vector <int> suffMax(n);
        int maxScore = 0;
        for(int i = n - 1; i >= 0; i--){
            if(i + 1 < n){
                maxScore = max(maxScore, i + a[i] + suffMax[i + 1]);
            }
            if(i == n - 1){
                suffMax[i] = a[i] - i;
            }
            else{
                suffMax[i] = max(suffMax[i + 1], a[i] - i);
            }
        }
        return maxScore;
    }
};
