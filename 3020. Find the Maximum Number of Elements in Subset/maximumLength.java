class Solution {
    public int maximumLength(int[] nums) {
        HashMap<Integer, Integer> map = new HashMap<>();
        ArrayList<Integer> list = new ArrayList<>();

        for (int num : nums) {
            map.put(num, map.getOrDefault(num, 0) + 1);
            if (map.get(num) == 1)
                list.add(num);
        }

        Collections.sort(list);
        int i = 0;

        Set<Integer> used = new HashSet<>();
        int ct = 1;

        // for pattern like - [1], [1,1,1], [1,1,1,1,1], etc...
        if (map.containsKey(1)) {
            int val = map.get(1);
            if (val % 2 == 0)
                val--;
            ct = val;
            used.add(1);
        }

        while (i < list.size()) {
            int top = list.get(i++);
            if (!used.add(top))
                continue;

            int curr = 0;
            while (map.getOrDefault(top, 0) > 1) {
                used.add(top);
                top *= top;
                curr += 2;
            }

            if (map.getOrDefault(top, 0) == 1) {
                curr += 2;
            }

            ct = Math.max(curr - 1, ct);
        }

        return ct;
    }
}