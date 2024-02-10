class Solution {
    public int isPalindrom(String s,int l,int h){

        int cnt = 0;
        while(l>=0 && h<s.length() && s.charAt(l--)==s.charAt(h++)) cnt++;
        return cnt;
    }
    public int countSubstrings(String s) {
        
        int res = 0;
        int n = s.length();
        for(int i=0;i<n;i++){

            res += isPalindrom(s,i,i);

            res += isPalindrom(s,i,i+1);
        }

        return res;
    }
}