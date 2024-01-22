class Solution {
    public int[] findErrorNums(int[] nums) {

        int n = nums.length;
        int freq[] = new int[n + 1];

        for (int val : nums) {
            freq[val]++;
        }

        int dupli = 0, missing = 0;
        for (int i = 1; i < n + 1; i++) {
            if (freq[i] == 2)
                dupli = i;
            if (freq[i] == 0)
                missing = i;
        }
        return new int[] { dupli, missing };
    }
}