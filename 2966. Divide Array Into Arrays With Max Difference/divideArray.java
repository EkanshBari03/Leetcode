class Solution {
    public int[][] divideArray(int[] nums, int k) {
       Arrays.sort(nums);

        int n = nums.length;
        int[][] ans = new int[n / 3][3];
        int index = 0;

        for (int i = 0; i < n; i += 3) {
            // i, i+1, i+2
            if (i + 2 < n && nums[i + 2] - nums[i] > k) {
                return new int[0][0]; // Returning an empty array if condition is not met
            }

            ans[index++] = new int[]{nums[i], nums[i + 1], nums[i + 2]};
        }

        return ans;
    }
}