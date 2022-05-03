class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        vector <int> suffMin;
        for(int i = n - 1; i >= 0; --i){
            if(suffMin.empty()){
                suffMin.push_back(nums[i]);
            }
            else{
                suffMin.push_back(min(suffMin.back(), nums[i]));
            }
        }
        reverse(suffMin.begin(), suffMin.end());
        int L = n - 1;
        for(int i = 0; i + 1 < n; ++i){
            if(nums[i] > suffMin[i + 1]){
                L = i;
                break;
            }
        }
        
        vector <int> prefMax;
        for(int x : nums){
            if(prefMax.empty()){
                prefMax.push_back(x);
            }
            else{
                prefMax.push_back(max(prefMax.back(), x));
            }
        }
        for(int i = n - 1; i >= 1; --i){
            if(prefMax[i - 1] > nums[i]){
                return i - L + 1;
            }
        }
        return 0;
    }
};
