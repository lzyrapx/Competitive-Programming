class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    vector<int>ve; // It is a set
    map<int,int>mp;
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(mp.count(val)) return false; // 已存在
        else {
            mp[val] = (int)ve.size();
            ve.push_back(val);
            /*
            mp[val] = ve.size();
            ve[ve.size()] = val
            */
        }
        return true;
    }
    // O(1)
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(!mp.count(val)) return false; // 不存在
        
        int last = ve.back();
        mp[last] = mp[val];
        ve[mp[val]] = last;
        
        ve.pop_back();
        mp.erase(val);
        
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return ve[rand() % (int)ve.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */