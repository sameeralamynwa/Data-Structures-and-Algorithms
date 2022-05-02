class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int l = 0, r = 0, n = (int) nums.size();
        while(l < n and r < n){
            while(l < n and (nums[l] & 1) == 0){
                ++l;
            }
            r = max(r, l + 1);
            while(r < n and nums[r] & 1){
                ++r;
            }
            if(r < n){
                swap(nums[l], nums[r]);
            }
            l++;
        }
        return nums;
    }
};
