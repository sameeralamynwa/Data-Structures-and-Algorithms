class Solution {
    public static int max(int x, int y){
        return x > y ? x : y;
    }
    
    public int lengthOfLongestSubstring(String s) {
        int l = 0, r = 0, longest = 0, n = s.length();
        boolean [] occured = new boolean [128];
        while(l < n){
            while(r < n){
                if(occured[(int) s.charAt(r)] == false){
                    occured[(int) s.charAt(r)] = true;
                }
                else{
                    break;
                }
                ++r;
            }
            longest = max(longest, r - l);
            occured[(int) s.charAt(l)] = false;
            ++l;
        }
        return longest;
    }
};
