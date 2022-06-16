class Solution {
public:
    int majorityElement(vector <int> &nums) {
        int mostFrequentElement = *nums.begin(), count = 1;
        nums.erase(nums.begin());
        for(int x : nums){
            if(x == mostFrequentElement){
                ++count;
            }
            else if(--count == 0){
                mostFrequentElement = x;
                ++count;
            }
        }
        return mostFrequentElement;
    }
};
