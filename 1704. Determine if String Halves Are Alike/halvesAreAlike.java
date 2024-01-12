class Solution {
    public boolean isVowel(char c) {
        if (c == 'a' || c == 'A')
            return true;
        else if (c == 'e' || c == 'E')
            return true;
        else if (c == 'i' || c == 'I')
            return true;
        else if (c == 'o' || c == 'O')
            return true;
        else if (c == 'u' || c == 'U')
            return true;

        return false;
    }

    public boolean halvesAreAlike(String s) {

        int n = s.length();
        int total = 0, cur = 0;
        for (int i = 0; i < n; i++) {

            if (isVowel(s.charAt(i))) {
                total++;
                if (i < n / 2)
                    cur++;
            }
        }

        return 2 * cur == total;
    }
}