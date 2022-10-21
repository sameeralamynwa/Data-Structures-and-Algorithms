class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        HashMap <Integer, Integer> lastOccuredAt = new HashMap <>();
        for(int i = 0; i < nums.length; ++i){
            if(lastOccuredAt.containsKey(nums[i])){
                if(i - lastOccuredAt.get(nums[i]) <= k){
                    return true;
                }
            }
            lastOccuredAt.put(nums[i], i);
        }
        return false;
    }
}
