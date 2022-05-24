class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.rbegin(), citations.rend());
        int maxHIndex = 0;
        for(int i = 0; i < (int) citations.size(); ++i){
            if(citations[i] > i){
                maxHIndex = i + 1;
            }
        }
        return maxHIndex;
    }
};
