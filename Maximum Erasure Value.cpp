class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int l = 0, r = 0, scoreSum = 0, maxScore = 0;
        unordered_set <int> elements;
        while(l < (int) nums.size()){
            while(r < (int) nums.size() and elements.find(nums[r]) == elements.end()){
                scoreSum += nums[r];
                elements.insert(nums[r++]);
            }
            maxScore = max(maxScore, scoreSum);
            scoreSum -= nums[l];
            elements.erase(nums[l++]);
        }
        return maxScore;
    }
};
