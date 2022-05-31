class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector <vector <int> > minCoins(2, vector <int> (amount + 1, amount + 1));
        int n = coins.size(), parity = 1;
        for(int sum = 0; sum <= amount; ++sum){
            for(int pos = 0; pos < n; ++pos){
                if(sum == coins[pos]){
                    minCoins[parity][sum] = 1;
                }
                else if(sum > coins[pos]){
                    minCoins[parity][sum] = min(minCoins[parity ^ 1][sum], 1 + minCoins[parity][sum - coins[pos]]);
                }
                else{
                    minCoins[parity][sum] = min(minCoins[parity][sum], minCoins[parity ^ 1][sum]);
                }
                minCoins[parity ^ 1][sum] = minCoins[parity][sum];
                parity ^= 1;
            }
        }
        return amount == 0 ? 0 : minCoins[parity][amount] > amount ? -1 : minCoins[parity][amount];
    }
};
