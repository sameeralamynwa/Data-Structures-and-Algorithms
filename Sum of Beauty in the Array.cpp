class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        vector <int> suffixMin((int) nums.size());
        for(int i = (int) nums.size() - 1; i >= 0; --i){
            if(i == (int) nums.size() - 1){
                suffixMin[i] = nums[i];
            }
            else{
                suffixMin[i] = min(suffixMin[i + 1], nums[i]);
            }
        }
        int beauty = 0, maxLeft = *nums.begin();
        for(int i = 1; i + 1 < (int) nums.size(); ++i){
            if(nums[i] > maxLeft and nums[i] < suffixMin[i + 1]){
                beauty += 2;
            }
            else if(nums[i - 1] < nums[i] and nums[i] < nums[i + 1]){
                beauty += 1;
            }
            maxLeft = max(maxLeft, nums[i]);
        }
        return beauty;
    }
};
