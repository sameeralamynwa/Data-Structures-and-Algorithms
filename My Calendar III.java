class MyCalendarThree {
    TreeMap <Integer, Integer> count;
    int k;
    
    public MyCalendarThree() {
        count = new TreeMap <>();
        k = 0;
    }
    
    public int book(int start, int end) {
        if(count.containsKey(start) == false){
            count.put(start, 0);
        }
        if(count.containsKey(end) == false){
            count.put(end, 0);
        }
        
        count.put(start, count.get(start) + 1);
        count.put(end, count.get(end) - 1);
        
        int ongoing = 0;
        for(int event : count.keySet()){
            ongoing += count.get(event);
            k = Math.max(k, ongoing);
        }
        
        return k;
    }
}
