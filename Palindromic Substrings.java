class Solution {
    public static int oddLength(int middle, String s){
        int left = middle, right = middle, count = 0;
        while(left >= 0 && right < s.length() && s.charAt(left--) == s.charAt(right++)){
            ++count;
        }
        return count;
    }

    public static int evenLength(int middle, String s){
        int left = middle, right = middle + 1, count = 0;
        while(left >= 0 && right < s.length() && s.charAt(left--) == s.charAt(right++)){
            ++count;
        }
        return count;
    }

    public int countSubstrings(String s) {
        int palindromicSubstrings = 0;
        for(int i = 0; i < s.length(); ++i){
            palindromicSubstrings += oddLength(i, s);
            palindromicSubstrings += evenLength(i, s);
        }
        return palindromicSubstrings;
    }
}
