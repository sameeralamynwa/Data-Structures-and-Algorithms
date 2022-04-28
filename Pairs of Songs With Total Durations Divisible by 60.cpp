class Solution {
private:
    const int sixty = 60;
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int numOfPairs = 0;
        vector <int> valueAt(sixty, 0);
        for(int t : time){
            if(valueAt[(sixty - t % sixty) % sixty]){
                numOfPairs += valueAt[(sixty - t % sixty) % sixty];
            }
            valueAt[t % sixty]++;
        }
        return numOfPairs;
    }
};
