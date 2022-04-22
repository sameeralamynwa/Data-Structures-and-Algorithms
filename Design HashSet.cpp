class MyHashSet {
public:
    
    const int size = 1e3;
    vector <vector <int> > container;
    
    MyHashSet() {
        container.resize(size);
    }
    
    int hashedValue(int key){
        return ((long long) key * key * key + (long long) key * key + key) % size;
    }
    
    void add(int key) {
        int index = hashedValue(key);
        if(search(key) == container[index].end()){
            container[index].push_back(key);
        }
    }
    
    vector <int> :: iterator search(int key){
        int index = hashedValue(key);
        return find(container[index].begin(), container[index].end(), key);
    }
    
    void remove(int key) {
        int index = hashedValue(key);
        if(search(key) != container[index].end()){
            container[index].erase(search(key));
        }
    }
    
    bool contains(int key) {
        int index = hashedValue(key);
        return search(key) != container[index].end();
    }
};
