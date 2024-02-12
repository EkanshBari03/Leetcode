class Solution {
    public int majorityElement(int[] nums) {
        
        int n = nums.length;
        int pivot = n/2;
        Map<Integer,Integer> m = new HashMap<>();
        for(int i=0;i<n;i++){
            int val = m.getOrDefault(nums[i],0);
            m.put(nums[i],val+1);
        }
        for(Map.Entry <Integer,Integer> it : m.entrySet()){
            if(it.getValue() > pivot) return it.getKey();
             
        }
        return -1;
    }
}