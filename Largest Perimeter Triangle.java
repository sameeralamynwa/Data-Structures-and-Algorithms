class Solution {
    public int largestPerimeter(int[] nums) {
        Arrays.sort(nums);
        int l = 1, r = 2;
        int maxPerimeter = 0;
        while(l + 1 < nums.length){
            while(r < nums.length && nums[r] < nums[l] + nums[l - 1]){
                ++r;
            }
            if(r - l > 1){
                maxPerimeter = Math.max(maxPerimeter, nums[r - 1] + nums[l] + nums[l - 1]);
            }
            ++l;
        }
        return maxPerimeter;
    }
}
