class Solution {
    public int change(int amount, int[] coins) {
        int[][] ways = new int[2][amount + 1];
        ways[0] = new int [amount + 1];
        for(int index = 0; index < coins.length; ++index){
            ways[1] = new int[amount + 1];
            for(int sum = 0; sum <= amount; ++sum){
                ways[1][sum] = ways[0][sum];
                if(sum == coins[index]){
                    ++ways[1][sum];
                }
                else if(sum > coins[index]){
                    ways[1][sum] += ways[1][sum - coins[index]];
                }
            }
            ways[0] = ways[1];
        }
        return amount == 0 ? 1 : ways[1][amount];
    }
}
