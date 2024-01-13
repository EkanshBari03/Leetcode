class Solution {
    public int minSteps(String s, String t) {

        int freq[] = new int[26];
        for (char c : s.toCharArray()) {
            freq[c - 'a']++;
        }
        for (char c : t.toCharArray()) {
            freq[c - 'a']--;
        }
        int sum = 0;
        for (int val : freq) {
            if (val < 0)
                sum += val;
        }

        return Math.abs(sum);

    }
}