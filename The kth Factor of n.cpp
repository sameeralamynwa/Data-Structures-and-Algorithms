class Solution {
public:
    int kthFactor(int n, int k) {
        for(int d = 1; d * d < n; ++d){
            if(n % d == 0 and --k == 0){
                return d;
            }
        }
        
        for(int d = sqrt(n); d >= 1; d--){
            if(n % d == 0 and --k == 0){
                return n / d;
            }
        }
        
        return -1;
    }
};
