class Solution {
    public int min(int x, int y){
        return x < y ? x : y;
    }
    
    public int max(int x, int y){
        return x > y ? x : y;
    }
    
    public int maxProfit(int[] prices) {
        int maxProfit = 0;
        for(int i = 0; i < prices.length; ++i){
            if(i > 0){
                maxProfit = max(maxProfit, prices[i] - prices[i - 1]);
                prices[i] = min(prices[i], prices[i - 1]);
            }
        }
        return maxProfit;
    }
}
