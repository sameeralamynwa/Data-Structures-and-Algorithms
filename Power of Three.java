class Solution {
    public boolean isPowerOfThree(int n) {
        return n % 3 != 0 ? n == 1 ? true : false : n > 0 ? isPowerOfThree(n / 3) : false;
    }
}
