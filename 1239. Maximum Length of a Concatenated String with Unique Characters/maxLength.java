class Solution {
    Map<String, Integer> dp;

    public boolean hasDuplicate(String s1, String s2) {
        int[] freq = new int[26];
        for (char c : s1.toCharArray()) {
            if (freq[c - 'a'] > 0) {
                return true;
            }
            freq[c - 'a']++;
        }
        for (char c : s2.toCharArray()) {
            if (freq[c - 'a'] > 0) {
                return true;
            }
        }
        return false;
    }

    public int solve(int ind, int n, String temp, List<String> nums) {
        if (ind >= n) {
            return temp.length();
        }
        if (dp.containsKey(temp)) {
            return dp.get(temp);
        }
        int take = 0;
        int skip = 0;
        if (hasDuplicate(nums.get(ind), temp)) {
            skip = solve(ind + 1, n, temp, nums);
        } else {
            skip = solve(ind + 1, n, temp, nums);
            take = solve(ind + 1, n, temp + nums.get(ind), nums);
        }

        int result = Math.max(take, skip);
        dp.put(temp, result);
        return result;
    }

    public int maxLength(List<String> arr) {
        dp = new HashMap<>();
        String temp = "";
        return solve(0, arr.size(), temp, arr);
    }
}