class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        map <int, int> occured;
        int kDiffPairs = 0;
        for(int x : nums){
            if(occured.find(x) == occured.end()){
                occured.insert({x, 1});
            }
            else if(k == 0){
                kDiffPairs += occured[x]++ == 1;
            }
        }
        if(k > 0){
            for(int x : nums){
                int next = x + k;
                while(occured.find(next) != occured.end()){
                    occured.erase(next);
                    next += k;
                }
                kDiffPairs += (next - x - k) / k;
                next = x - k;
                while(occured.find(next) != occured.end()){
                    occured.erase(next);
                    next -= k;
                }
                kDiffPairs += (x - next - k) / k;
                occured.erase(x);
            }
        }
        
        return kDiffPairs;
    }
};
