class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        bool nthPresent = find(nums.begin(), nums.end(), (int) nums.size()) != nums.end();
        for(int &x : nums){
            if(x < 0){
                x = (int) nums.size() + 1;
            }
        }
        for(int i = 0; i < (int) nums.size(); ++i){
            int currentIndex = nums[i];
            while(currentIndex >= 0 and currentIndex < (int) nums.size()){
                int nextIndex = nums[currentIndex];
                nums[currentIndex] = -1;
                currentIndex = nextIndex;
            }
        }
        for(int i = 1; i < (int) nums.size(); ++i){
            if(nums[i] != -1){
                return i;
            }
        }
        return nthPresent + (int) nums.size();
    }
};
