class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        map <int, int> valueAt;
        int sum = nums[0] % k;
        valueAt[sum] = 0;
        for(int i = 1; i < (int) nums.size(); ++i){
            sum += nums[i];
            sum %= k;
            if(sum == 0 or valueAt.find(sum) != valueAt.end()){
                if(sum == 0 or valueAt[sum] < i - 1){
                    return true;
                }
            }
            if(valueAt.find(sum) == valueAt.end()){
                valueAt[sum] = i;
            }
        }
        return false;
    }
};
