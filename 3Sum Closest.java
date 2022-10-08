class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int justAbove = Integer.MAX_VALUE, justBelow = Integer.MIN_VALUE;
        for(int first = 0; first < nums.length; ++first){
            int second = first + 1, third = nums.length - 1;
            while(second < third){
                if(nums[first] + nums[second] + nums[third] < target){
                    ++second;
                }
                else if(nums[first] + nums[second] + nums[third] == target){
                    return target;
                }
                else{
                    justAbove = Math.min(justAbove, nums[first] + nums[second] + nums[third]);
                    --third;
                }
            }
            second = first + 1;
            third = nums.length - 1;
            while(second < third){
                if(nums[first] + nums[second] + nums[third] > target){
                    --third;
                }
                else if(nums[first] + nums[second] + nums[third] == target){
                    return target;
                }
                else{
                    justBelow = Math.max(justBelow, nums[first] + nums[second] + nums[third]);
                    ++second;
                }
            }
        }
        if(justBelow == Integer.MIN_VALUE){
            return justAbove;
        }
        else if(justAbove == Integer.MAX_VALUE){
            return justBelow;
        }
        else{
            return target - justBelow < justAbove - target ? justBelow : justAbove;
        }
    }
}
