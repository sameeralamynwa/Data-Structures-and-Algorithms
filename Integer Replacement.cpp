class Solution {
public:
    void solve(long long n, int currentOperations, int &minOperations){
        if(n == 1){
            minOperations = min(minOperations, currentOperations);
            return;
        }
        if(currentOperations >= minOperations){
            return;
        }
        if(n & 1){
            solve(n - 1, currentOperations + 1, minOperations);
            solve(n + 1, currentOperations + 1, minOperations);
        }
        else{
            solve(n >> 1, currentOperations + 1, minOperations);
        }
    }
    int integerReplacement(int n) {
        int minOperations = n;
        solve(n, 0, minOperations);
        return minOperations;
    }
};
