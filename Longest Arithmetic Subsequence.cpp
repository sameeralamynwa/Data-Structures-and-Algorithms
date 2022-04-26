class Solution {
private:
    const int nax = 5.1e2;
public:
    int longestArithSeqLength(vector<int>& nums) {
        int longestAP = 0;
        for(int commonDifference = -nax; commonDifference <= nax; commonDifference++){
            vector <int> endingAt(nax, 0);
            for(int x : nums){
                if(commonDifference == 0){
                    endingAt[x]++;
                }
                else{
                    if(x - commonDifference >= 0 and x - commonDifference < nax){
                        endingAt[x] = endingAt[x - commonDifference] + 1;
                    }
                }
                endingAt[x] = max(endingAt[x], 1);
                longestAP = max(longestAP, endingAt[x]);
            }
        }
        return longestAP;
    }
};
