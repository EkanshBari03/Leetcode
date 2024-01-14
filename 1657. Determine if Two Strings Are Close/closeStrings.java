class Solution {
    public boolean closeStrings(String word1, String word2) {
        
        int f1[]  = new int[26];
        int f2[]  = new int[26];
        int w1[]  = new int[26];
        int w2[]  = new int[26];

        for(char c:word1.toCharArray()){
            f1[c-'a']++;
            w1[c-'a'] = 1;
        }
        for(char c: word2.toCharArray()){
            f2[c-'a']++;
            w2[c-'a'] = 1;
        }

        Arrays.sort(f1);
        Arrays.sort(f2);

        return Arrays.equals(f1,f2) && Arrays.equals(w1,w2);
    }
}