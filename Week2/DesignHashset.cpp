#define ARR 1000000

class MyHashSet {
public:
    bool set[ARR];
    /** Initialize your data structure here. */
    MyHashSet() {
        for(int i = 0; i < ARR; i++)
            set[i] = false;
    }
    
    void add(int key) {
        set[key] = true;
    }
    
    void remove(int key) {
        set[key] = false;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return set[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */