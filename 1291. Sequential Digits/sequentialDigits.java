class Solution {
    public List<Integer> sequentialDigits(int low, int high) {
        List<Integer> ans = new ArrayList<>();
        String s = "123456789";
        int n = s.length();

        for (int len = 2; len <= n; len++) {
            for (int startInd = 0; startInd <= n - len; startInd++) {
                String temp = s.substring(startInd, startInd + len);
                int val = Integer.parseInt(temp);

                if (val >= low && val <= high) {
                    ans.add(val);
                }
            }
        }

        return ans;
    }
}