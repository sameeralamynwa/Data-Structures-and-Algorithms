class Solution {
    public int bagOfTokensScore(int[] tokens, int power) {
        Arrays.sort(tokens);
        int start = 0, end = tokens.length - 1, score = 0, maxScore = 0;
        while(start <= end){
            if(power >= tokens[start]){
                score++;
                power -= tokens[start++];
            }
            else if(score > 0){
                power += tokens[end--];
                score--;
            }
            else{
                break;
            }
            maxScore = Math.max(maxScore, score);
        }
        return maxScore;
    }
}
