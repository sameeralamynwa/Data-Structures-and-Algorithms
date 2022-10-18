class Solution {
    public String countAndSay(int n) {
        HashMap <Integer, String> countAndSay = new HashMap <>();
        countAndSay.put(1, "1");
        for(int term = 2; term <= n; ++term){
            String previous = countAndSay.get(term - 1);
            String current = new String();
            for(int index = 0; index < previous.length();){
                int sameTillIndex = index;
                while(sameTillIndex < previous.length() && previous.charAt(sameTillIndex) == previous.charAt(index)){
                    ++sameTillIndex;
                }
                current += Integer.toString(sameTillIndex - index);
                current += previous.charAt(index);
                index = sameTillIndex;
            }
            countAndSay.put(term, current);
        }
        return countAndSay.get(n);
    }
}
