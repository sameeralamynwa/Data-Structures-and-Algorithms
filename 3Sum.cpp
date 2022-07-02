class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector <vector <int> > triplets;
        sort(nums.begin(), nums.end());
        for(int first = 0; first + 2 < n; ++first){
            if(first > 0 and nums[first] == nums[first - 1]){
                continue;
            }
            int second = first + 1, third = n - 1;
            while(second < third){
                if(second > first + 1 and nums[second] == nums[second - 1]){
                    ++second;
                }
                else if(nums[second] + nums[third] > -nums[first]){
                    --third;
                }
                else if(nums[second] + nums[third] == -nums[first]){
                    triplets.push_back({nums[first], nums[second], nums[third]});
                    ++second;
                    --third;
                }
                else{
                    ++second;
                }
            }
        }
        return triplets;
    }
};
