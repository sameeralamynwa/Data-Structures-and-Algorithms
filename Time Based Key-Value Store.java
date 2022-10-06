class TimeMap {
    HashMap <String, TreeMap <Integer, String> > store;
    
    public TimeMap() {
        store = new HashMap <>();
    }
    
    public void set(String key, String value, int timestamp) {
        if(store.containsKey(key) == false){
            store.put(key, new TreeMap <>());
        }
        store.get(key).put(timestamp, value);
    }
    
    public String get(String key, int timestamp) {
        String value = new String();
        if(store.containsKey(key)){
            Integer previousTimeStamp = store.get(key).floorKey(timestamp);
            if(previousTimeStamp != null){
                value = store.get(key).get(previousTimeStamp);
            }
        }
        return value;
    }
}
