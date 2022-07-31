class Solution {
    public int singleNonDuplicate(int[] nums) {
        int low = 0, high = nums.length - 1, singleIndex = 0;
        while(low <= high){
            int mid = (low + high) >> 1;
            if(mid % 2 == 1){
                if(nums[mid] == nums[mid - 1]){
                    low = mid + 1;
                }
                else{
                    singleIndex = mid;
                    high = mid - 1;
                }
            }
            else{
                if(mid + 1 < nums.length && nums[mid] == nums[mid + 1]){
                    low = mid + 1;
                }
                else{
                    singleIndex = mid;
                    high = mid - 1;
                }
            }
        }
        return nums[singleIndex];
    }
}
