class Solution {
    public int subarraySum(int[] nums, int k) {
        Map<Integer, Integer> map = new HashMap<>();
        int preSum = 0, cnt = 0;

        for (int num : nums) {
            preSum += num;

            if (preSum == k) {
                cnt++;
            }

            if (map.containsKey(preSum - k)) {
                cnt += map.get(preSum - k);
            }

            map.put(preSum, map.getOrDefault(preSum, 0) + 1);
        }

        return cnt;
    }
}