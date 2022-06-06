class Solution {
public:
    int candy(vector<int>& ratings) {
        vector <int> leftDirectionCandies((int) ratings.size());
        for(int i = 0; i < (int) ratings.size(); ++i){
            if(i == 0 or ratings[i] <= ratings[i - 1]){
                leftDirectionCandies[i] = 1;
            }
            else{
                leftDirectionCandies[i] = leftDirectionCandies[i - 1] + 1;
            }
        }
        int rightDirectionCandies = 0, totalCandies = 0;
        for(int i = (int) ratings.size() - 1; i >= 0; --i){
            if(i + 1 == (int) ratings.size() or ratings[i] <= ratings[i + 1]){
                rightDirectionCandies = 1;
            }
            else{
                ++rightDirectionCandies;
            }
            totalCandies += max(rightDirectionCandies, leftDirectionCandies[i]);
        }
        return totalCandies;
    }
};
