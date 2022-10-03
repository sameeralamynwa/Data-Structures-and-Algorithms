class Solution {
    public int minCost(String colors, int[] neededTime) {
        int totalTimeNeeded = 0;
        for(int i = 0; i < colors.length();){
            int maxTime = neededTime[i];
            int j = i + 1;
            totalTimeNeeded += neededTime[i];
            while(j < colors.length() && colors.charAt(j) == colors.charAt(i)){
                totalTimeNeeded += neededTime[j];
                maxTime = Math.max(maxTime, neededTime[j]);
                ++j;
            }
            i = j;
            totalTimeNeeded -= maxTime;
        }
        return totalTimeNeeded;
    }
}
