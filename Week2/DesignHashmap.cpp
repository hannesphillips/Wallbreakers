class MyHashMap {
    vector<int> k;
    vector<int> val;
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int i;
        for(i = 0; i < k.size(); i++)
            if(k[i] == key)
                break;
        
        if(i == k.size()) {
            k.push_back(key);
            val.push_back(value);
        }
        else
            val[i] = value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        for(int i = 0; i < k.size(); i++)
            if(k[i] == key) return val[i];
        
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        for(int i = 0; i < k.size(); i++)
            if(k[i] == key) {
                k.erase(k.begin() + i);
                val.erase(val.begin() + i);
            }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */