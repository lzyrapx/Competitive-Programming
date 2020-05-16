/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-05-15 23:49:53
 */ 
class RangeModule {
public:
    RangeModule() {
        
    }
    map<int,int>mp;
    void addRange(int left, int right) {
        int start = left;
        int end = right;
        // map: [1,4], [6, 9], [12, 15]
        // [3, 8]
        auto l = mp.upper_bound(left);
        if(l != mp.begin() && prev(l) -> second >= left) {
            start = prev(l) -> first;
        }
        auto r = mp.upper_bound(right);
        if(r != mp.begin() && prev(r) -> second >= right) {
            end = prev(r) -> second;
        }
        mp.erase(l, r); // erase [l, r)
        mp[start] = end;
    }
    
    bool queryRange(int left, int right) {
        auto l = mp.upper_bound(left);
        if(l == mp.begin() || prev(l) -> second < right) {
            return false;
        }
        return true;
    }
    
    void removeRange(int left, int right) {
        auto r = mp.upper_bound(right);
        if(r != mp.begin() && prev(r) -> second > right) {
            mp[right] = prev(r) -> second;
        }
        auto l = mp.upper_bound(left);
        if(l != mp. begin() && prev(l) -> second > left) {
            prev(l) -> second = left;
        }
        mp.erase(mp.lower_bound(left), mp.lower_bound(right)); // erase: [l, r]
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */