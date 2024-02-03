class Solution {
    public int maxSumAfterPartitioning(int[] arr, int k) {
        
        int dp[] = new int[501];
        int n = arr.length;

        for(int size = 1;size<=n;size++){
            int currmax = -1;
            for(int j = 1;j<=k && size-j>=0;j++){
                currmax = Math.max(currmax,arr[size-j]);

                dp[size] = Math.max(dp[size],(j*currmax) + dp[size-j]);
            }
        }
        return dp[n];
    }
}