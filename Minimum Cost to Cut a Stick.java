class Solution {
    public int minCost(int rodLength, int[] cuts) {
        Arrays.sort(cuts);
        int[] modifiedCuts = prepareCutsArray(rodLength, cuts);

        int[][] dp = new int[modifiedCuts.length][modifiedCuts.length];
        fillMinCostDP(modifiedCuts, dp);

        return dp[0][modifiedCuts.length - 1];
    }

    private int[] prepareCutsArray(int rodLength, int[] cuts) {
        int[] modifiedCuts = new int[cuts.length + 2];
        modifiedCuts[0] = 0;
        modifiedCuts[modifiedCuts.length - 1] = rodLength;
        System.arraycopy(cuts, 0, modifiedCuts, 1, cuts.length);
        return modifiedCuts;
    }

    private void fillMinCostDP(int[] modifiedCuts, int[][] dp) {
        for (int len = 2; len < modifiedCuts.length; len++) {
            for (int start = 0; start + len < modifiedCuts.length; start++) {
                int end = start + len;
                dp[start][end] = Integer.MAX_VALUE;
                for (int i = start + 1; i < end; i++) {
                    dp[start][end] = Math.min(dp[start][end], modifiedCuts[end] - modifiedCuts[start] + dp[start][i] + dp[i][end]);
                }
            }
        }
    }
}
