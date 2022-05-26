class Solution {
public:
    int hammingWeight(uint32_t n) {
        int oneBits = 0;
        while(n > 0 and ++oneBits){
            n &= n - 1;
        }
        return oneBits;
    }
};
