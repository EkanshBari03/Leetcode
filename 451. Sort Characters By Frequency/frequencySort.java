class Solution {
    public String frequencySort(String s) {
        Map<Character, StringBuilder> frequencyMap = new HashMap<>();
        PriorityQueue<Map.Entry<Character, StringBuilder>> maxHeap = new PriorityQueue<>(
            (a, b) -> Integer.compare(b.getValue().length(), a.getValue().length())
        );

        for (char c : s.toCharArray()) {
            frequencyMap.computeIfAbsent(c, k -> new StringBuilder()).append(c);
        }

        maxHeap.addAll(frequencyMap.entrySet());

        StringBuilder result = new StringBuilder();

        while (!maxHeap.isEmpty()) {
            Map.Entry<Character, StringBuilder> entry = maxHeap.poll();
            result.append(entry.getValue());
        }

        return result.toString();
    }
}