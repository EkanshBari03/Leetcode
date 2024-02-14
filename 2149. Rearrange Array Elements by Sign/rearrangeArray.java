class Solution {
    public int[] rearrangeArray(int[] nums) {
        
        int pos = 0;
        int neg = 1;
        int n = nums.length;
        int ans[]  = new int[n];
        for(int val : nums){
            if(val<0){
                ans[neg] = val;
                neg = neg + 2;
            } else { 
                ans[pos] = val;
                pos = pos + 2;
            }
        }

        return ans;
    }
}