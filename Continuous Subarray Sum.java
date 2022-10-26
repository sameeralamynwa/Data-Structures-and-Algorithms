class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {
        int currentSum = 0;
        HashMap <Integer, Integer> cumulativeSumAt = new HashMap <>();
        for(int index = 0; index < nums.length; ++index){
            currentSum += nums[index];
            currentSum %= k;
            if(cumulativeSumAt.containsKey(currentSum)){
                if(index - cumulativeSumAt.get(currentSum) > 1){
                    return true;
                }
            }
            else{
                cumulativeSumAt.put(currentSum, index);
            }
            if(currentSum == 0 && index > 0){
                return true;
            }
        }
        return false;
    }
}
