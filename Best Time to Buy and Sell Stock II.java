class Solution {
    int max(int x, int y){
        return x > y ? x : y;
    }
    
    public int maxProfit(int[] prices) {
        int maxWithoutStock = 0, maxWithStock = 0;
        for(int i = 0; i < prices.length; ++i){
            if(i == 0){
                maxWithoutStock = 0;
                maxWithStock = -prices[i];
            }
            else{
                maxWithoutStock = max(maxWithoutStock, maxWithStock + prices[i]);
                maxWithStock = max(maxWithStock, maxWithoutStock - prices[i]);
            }
        }
        return maxWithoutStock;
    }
}
