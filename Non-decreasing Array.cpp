class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int i = 0;
        while(i + 1 < (int) nums.size() and nums[i] <= nums[i + 1] and ++i);
        if(i + 1 < (int) nums.size()){
            if(i == 0 or nums[i + 1] >= nums[i - 1]){
                nums[i] = nums[i + 1];
            }
            else{
                nums[i + 1] = nums[i];
            }
        }
        while(i + 1 < (int) nums.size() and nums[i] <= nums[i + 1] and ++i);
        return i + 1 == (int) nums.size();
    }
};
