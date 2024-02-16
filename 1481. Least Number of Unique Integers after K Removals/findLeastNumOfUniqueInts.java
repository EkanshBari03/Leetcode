class Solution {
    public int findLeastNumOfUniqueInts(int[] arr, int k) {
        Map<Integer, Integer> frequencyMap = new HashMap<>();

        for (int num : arr) {
            frequencyMap.put(num, frequencyMap.getOrDefault(num, 0) + 1);
        }

        PriorityQueue<Integer> minHeap = new PriorityQueue<>(Comparator.comparingInt(frequencyMap::get));

        for (int key : frequencyMap.keySet()) {
            minHeap.offer(key);
        }

        while (!minHeap.isEmpty() && k > 0) {
            int num = minHeap.poll();
            k -= frequencyMap.get(num);
            if (k >= 0) {
                frequencyMap.remove(num);
            }
        }

        return frequencyMap.size();
    }
}