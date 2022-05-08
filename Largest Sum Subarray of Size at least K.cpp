long long int maxSumWithK(long long a[], long long n, long long k) {
    vector <long long int> prefixMin(n);
    long long maxSum = -1e9, currentSum = 0;
    for(int i = 0; i < n; ++i){
        currentSum += a[i];
        if(i >= k - 1){
            maxSum = max(maxSum, currentSum);
            if(i >= k){
                maxSum = max(maxSum, currentSum - prefixMin[i - k]);
            }
        }
        if(i == 0){
            prefixMin[i] = currentSum;
        }
        else{
            prefixMin[i] = min(prefixMin[i - 1], currentSum);
        }
    }
    return maxSum;
}
