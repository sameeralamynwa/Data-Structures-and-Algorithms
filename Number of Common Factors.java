class Solution {
    public int computeGCD(int a, int b){
        return b == 0 ? a : computeGCD(b, a % b);
    }
    
    public int commonFactors(int a, int b) {
        int factors = 0;
        int gcd = computeGCD(a, b);
        for(int d = 1; d * d <= gcd; ++d){
            if(gcd % d == 0){
                ++factors;
                if(d != gcd / d){
                    ++factors;
                }
            }
        }
        return factors;
    }
}
