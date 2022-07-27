class Solution {
    public double myPow(double x, int n) {
        double result = 1;
        x = n < 0 ? 1 / x : x;
        while(n != 0){
            if(Math.abs(n) % 2 != 0){
                result *= x;
            }
            x *= x;
            n /= 2;
        }
        return result;
    }
}
