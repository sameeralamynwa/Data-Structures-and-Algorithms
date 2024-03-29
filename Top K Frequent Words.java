class Solution {
    public List<String> topKFrequent(String[] words, int k) {
        Map<String, Integer> wordCount = new HashMap<>();
        for (String word : words) {
            wordCount.put(word, wordCount.getOrDefault(word, 0) + 1);
        }
        
        PriorityQueue<String> pq = new PriorityQueue<>(
            (w1, w2) -> wordCount.get(w1).equals(wordCount.get(w2)) ? w2.compareTo(w1) : wordCount.get(w1) - wordCount.get(w2)
        );
        
        for (String word : wordCount.keySet()) {
            pq.offer(word);
            if (pq.size() > k) {
                pq.poll();
            }
        }
        
        List<String> topWords = new ArrayList<>();
        while (!pq.isEmpty()) {
            topWords.add(pq.poll());
        }
        Collections.reverse(topWords);
        
        return topWords;
    }
}
