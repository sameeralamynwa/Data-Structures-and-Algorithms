class Solution {
    public int maxProduct(int[] nums) {
        int minProduct = 1, maxProduct = 1, globalMaxProduct = Integer.MIN_VALUE;
        for(int x : nums){
            if(x > 0){
                maxProduct = x * maxProduct;
                minProduct = x * minProduct;
            }
            else{
                int previousMaxProduct = maxProduct;
                maxProduct = x * minProduct;
                minProduct = x * previousMaxProduct;
            }
            globalMaxProduct = Math.max(globalMaxProduct, maxProduct);
            maxProduct = Math.max(1, maxProduct);
            minProduct = Math.min(1, minProduct);
        }
        
        return globalMaxProduct;
    }
}
