class Solution {
    public List<Integer> largestDivisibleSubset(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;

        int[] t = new int[n];
        int[] prevInd = new int[n];

        Arrays.fill(t, 1);
        Arrays.fill(prevInd, -1);

        int lastIndex = 0;
        int maxL = 1;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0) {
                    if (t[i] < t[j] + 1) {
                        t[i] = t[j] + 1;
                        prevInd[i] = j;
                    }
                    if (t[i] > maxL) {
                        maxL = t[i];
                        lastIndex = i;
                    }
                }
            }
        }

        List<Integer> ans = new ArrayList<>();
        while (lastIndex != -1) {
            ans.add(nums[lastIndex]);
            lastIndex = prevInd[lastIndex];
        }

        return ans;
    }
}