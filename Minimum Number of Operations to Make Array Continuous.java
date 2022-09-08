class Solution {
    public int minOperations(int[] nums) {
        Arrays.sort(nums);
        int equal[] = new int [nums.length];
        for(int i = 0; i < nums.length; ++i){
            if(i > 0){
                equal[i] = equal[i - 1];
            }
            if(i > 0 && nums[i] == nums[i - 1]){
                equal[i]++;
            }
        }
        int minOperations = nums.length;
        for(int i = 0; i < nums.length; ++i){
            if(i > 0 && nums[i] == nums[i - 1]){
                continue;
            }
            int low = i, high = nums.length - 1, maxElementIndex = i;
            while(low <= high){
                int mid = (low + high) >> 1;
                if(nums[mid] <= nums[i] + nums.length - 1){
                    maxElementIndex = mid;
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
            minOperations = Math.min(minOperations, i + nums.length - maxElementIndex - 1 + equal[maxElementIndex] - equal[i]);
        }
        return minOperations;
    }
}
