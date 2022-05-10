class Solution {
private:
    const int mod = 1e9 + 7;
public:
    int lcm(int a, int b){
        return a * b / __gcd(a, b);
    }
    
    int nthMagicalNumber(int n, int a, int b) {
        long long low = min(a, b), high = (long long) n * max(a, b), nthMagical;
        while(low <= high){
            long long mid = (low + high) >> 1;
            if(mid / a + mid / b - mid / lcm(a, b) < n){
                low = mid + 1;
            }
            else{
                nthMagical = mid;
                high = mid - 1;
            }
        }
        return nthMagical % mod;
    }
};
