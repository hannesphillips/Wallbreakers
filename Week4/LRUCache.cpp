class LRUCache {
public:
    LRUCache(int capacity) {
        sz = capacity;
    }
    
    int get(int key) {
        if(cache.find(key) == cache.end()) return -1;
        
        // If key exists update usage then return value
        cached.remove(key);
        cached.push_back(key);
        return cache[key];
    }
    
    void put(int key, int value) {
        /* If key doesn't exist check if list is at capacity
        If so, remove least recent value then put new pair
        If key is present update usage and overwrite value */
        if(get(key) == -1) {
            if(cached.size() == sz) {
                cache.erase(cached.front());
                cached.pop_front();
            }
            cached.push_back(key);
            cache.insert({key, value});
        }
        else {
            cache[key] = value;
        }
    }
private:
    unordered_map<int, int> cache;
    list<int> cached;
    int sz;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */