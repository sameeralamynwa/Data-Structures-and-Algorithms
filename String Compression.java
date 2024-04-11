class Solution {
    public int compress(char[] chars) {
        int writeIdx = 0;
        
        for (int readIdx = 0; readIdx < chars.length; ++readIdx) {
            int consecutiveCount = 1;
            
            while (readIdx + 1 < chars.length && chars[readIdx + 1] == chars[readIdx]) {
                readIdx++;
                consecutiveCount++;
            }
            
            chars[writeIdx++] = chars[readIdx];
            
            if (consecutiveCount > 1) {
                for (char digit : Integer.toString(consecutiveCount).toCharArray()) {
                    chars[writeIdx++] = digit;
                }
            }
        }
        
        return writeIdx;
    }
}
