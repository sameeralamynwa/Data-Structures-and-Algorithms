class KthLargest {
    PriorityQueue <Integer> maxKElements;
    int k;
    
    public KthLargest(int k, int[] nums) {
        this.k = k;
        maxKElements = new PriorityQueue <>();
        for(int x : nums){
            maxKElements.add(x);
        }
    }
    
    public int add(int val) {
        maxKElements.add(val);
        while(maxKElements.size() > k){
            maxKElements.remove();
        }
        return maxKElements.peek();
    }
}
