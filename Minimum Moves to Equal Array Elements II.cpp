class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long sum = 0, sumSoFar = 0, minMoves;
        for(int i = 0; i < (int) nums.size(); ++i){
            sum += nums[i];
        }
        for(int i = 0; i < (int) nums.size(); ++i){
            if(i == 0){
                minMoves = sum + (long long) nums[i] * (2 * i + 2 - (int) nums.size()) - 2 * nums[i];
            }
            else{
                if(sum + (long long) nums[i] * (2 * i + 2 - (int) nums.size()) - 2 * (nums[i] + sumSoFar) < minMoves){
                    minMoves = sum + (long long) nums[i] * (2 * i + 2 - (int) nums.size()) - 2 * (nums[i] + sumSoFar);
                }
            }
            sumSoFar += nums[i];
        }
        return minMoves;
    }
};
