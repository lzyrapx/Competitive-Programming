class MyHashSet {
public:
    /** Initialize your data structure here. */
    vector<bool>ve;
    MyHashSet() {
        for(int i = 0; i <= 1000000; i++) {
            ve.push_back(false);
        }
    }
    
    void add(int key) {
        ve[key] = true;
    }
    
    void remove(int key) {
        ve[key] = false;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return ve[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * bool param_3 = obj.contains(key);
 */
