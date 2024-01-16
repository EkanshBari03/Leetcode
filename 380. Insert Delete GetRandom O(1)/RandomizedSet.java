class RandomizedSet {
    private List<Integer> nums;
    private Map<Integer, Integer> map;
    private Random rand;

    public RandomizedSet() {
        nums = new ArrayList<>();
        map = new HashMap<>();
        rand = new Random();
    }

    public boolean insert(int val) {
        if (map.containsKey(val)) {
            return false;
        }

        nums.add(val);
        map.put(val, nums.size() - 1);
        return true;
    }

    public boolean remove(int val) {
        if (!map.containsKey(val)) {
            return false;
        }

        int index = map.get(val);
        int lastElement = nums.get(nums.size() - 1);
        nums.set(index, lastElement);
        map.put(lastElement, index);
        nums.remove(nums.size() - 1);
        map.remove(val);
        return true;
    }

    public int getRandom() {
        int n = nums.size();
        return nums.get(rand.nextInt(n));
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */