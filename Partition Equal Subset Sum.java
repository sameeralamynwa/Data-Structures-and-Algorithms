class Solution {
    public boolean canPartition(int[] nums) {
        int totalSum = 0;
        for(int x : nums){
            totalSum += x;
        }
        
        if(totalSum % 2 != 0){
            return false;
        }
        
        boolean[][] canPartition = new boolean[2][1 + totalSum / 2];
        canPartition[0] = new boolean[1 + totalSum / 2];
        
        for(int i = 0; i < nums.length; ++i){
            canPartition[1] = new boolean[1 + totalSum / 2];
            for(int sum = 0; sum <= totalSum / 2; ++sum){
                canPartition[1][sum] = canPartition[0][sum];
                if(sum == nums[i]){
                    canPartition[1][sum] = true;
                }
                else if(sum > nums[i]){
                    canPartition[1][sum] |= canPartition[0][sum - nums[i]];
                }
            }
            canPartition[0] = canPartition[1];
        }
        
        return canPartition[1][totalSum / 2];
    }
}
