class Solution {
    public int removeDuplicates(int[] nums) {
        int distinct = 0;
        for(int i = 0; i < nums.length;){
            while(i + 1 < nums.length && nums[i] == nums[i + 1]){
                ++i;
            }
            nums[distinct++] = nums[i++];
        }
        return distinct;
    }
}
