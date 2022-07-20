class Solution {
    public int romanToInt(String s) {
        HashMap <Character, Integer> conversion = new HashMap<>();
        conversion.put('I', 1);
        conversion.put('V', 5);
        conversion.put('X', 10);
        conversion.put('L', 50);
        conversion.put('C', 100);
        conversion.put('D', 500);
        conversion.put('M', 1000);

        int value = conversion.get(s.charAt(s.length() - 1));
        for(int i = 0; i + 1 < s.length(); ++i){
            if(conversion.get(s.charAt(i)) < conversion.get(s.charAt(i + 1))){
                value -= conversion.get(s.charAt(i));
            }
            else{
                value += conversion.get(s.charAt(i));
            }
        }
        return value;
    }
}
