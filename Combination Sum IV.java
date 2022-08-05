class Solution {
    public int combinationSum4(int[] nums, int target) {
        int[] ways = new int[target + 1];
        for(int sum = 0; sum <= target; ++sum){
            for(int x : nums){
                if(sum == x){
                    ways[sum]++;
                }
                else if(sum > x){
                    ways[sum] += ways[sum - x];
                }
            }
        }
        return ways[target];
    }
}
