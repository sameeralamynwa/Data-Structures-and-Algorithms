class MedianFinder {
    PriorityQueue <Integer> lowerHalf, upperHalf;
    
    public MedianFinder() {
        lowerHalf = new PriorityQueue <>(Collections.reverseOrder());
        upperHalf = new PriorityQueue <>();
    }
    
    public void addNum(int num) {
        if(upperHalf.size() > 0 && num > upperHalf.peek()){
            upperHalf.add(num);
            if(upperHalf.size() > lowerHalf.size() + 1){
                lowerHalf.add(upperHalf.peek());
                upperHalf.remove();
            }            
        }
        else{
            lowerHalf.add(num);
            if(lowerHalf.size() > upperHalf.size() + 1){
                upperHalf.add(lowerHalf.peek());
                lowerHalf.remove();
            }
        }
    }
    
    public double findMedian() {
        if(upperHalf.size() == lowerHalf.size()){
            return (double) (upperHalf.peek() + lowerHalf.peek()) / 2;
        }
        return upperHalf.size() > lowerHalf.size() ? upperHalf.peek() : lowerHalf.peek();
    }
}
