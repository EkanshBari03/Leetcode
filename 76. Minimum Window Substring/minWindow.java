class Solution {
    public String minWindow(String s, String t) {
        if (s.length() < t.length()) {
            return "";
        }

        Map<Character, Integer> mp = new HashMap<>();
        for (int i = 0; i < t.length(); i++) {
            char c = t.charAt(i);
            mp.put(c, mp.getOrDefault(c, 0) + 1);
        }

        int count = t.length();
        int minWindowSize = Integer.MAX_VALUE;
        int startInd = 0;
        int i = 0, j = 0;
        String ans = "";

        while (j < s.length()) {
            char c = s.charAt(j);

            if (mp.containsKey(c) && mp.get(c) > 0) {
                count--;
            }
            mp.put(c, mp.getOrDefault(c, 0) - 1);

            while (count == 0) {
                int curWindowSize = j - i + 1;
                if (curWindowSize < minWindowSize) {
                    minWindowSize = curWindowSize;
                    startInd = i;
                }

                char leftChar = s.charAt(i);
                mp.put(leftChar, mp.getOrDefault(leftChar, 0) + 1);

                if (mp.containsKey(leftChar) && mp.get(leftChar) > 0) {
                    count++;
                }

                i++;
            }
            j++;
        }

        return minWindowSize == Integer.MAX_VALUE ? "" : s.substring(startInd, startInd + minWindowSize);
    }
}