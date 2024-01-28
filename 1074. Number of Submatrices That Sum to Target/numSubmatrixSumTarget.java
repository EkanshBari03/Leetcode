class Solution {
    public int numSubmatrixSumTarget(int[][] matrix, int target) {
       int row = matrix.length;
        int col = matrix[0].length;
        int[][] nums = new int[row][col];

        for (int i = 0; i < row; i++) {
            int sum = 0;
            for (int j = 0; j < col; j++) {
                sum = sum + matrix[i][j];
                nums[i][j] = sum;
            }
        }

        int cnt = 0;
        for (int sc = 0; sc < col; sc++) {
            for (int c = sc; c < col; c++) {
                Map<Integer, Integer> map = new HashMap<>();
                int presum = 0;
                for (int r = 0; r < row; r++) {
                    presum += nums[r][c] - (sc > 0 ? nums[r][sc - 1] : 0);
                    if (presum == target) {
                        cnt++;
                    }
                    if (map.containsKey(presum - target)) {
                        cnt += map.get(presum - target);
                    }
                    map.put(presum, map.getOrDefault(presum, 0) + 1);
                }
            }
        }

        return cnt; 
    }
}