// 使用map和list实现的LRU。 实现了get和put操作
class LRUCache {
private: 
    // 当缓存满了的时候，要移除list的最后一个，同时还要移除map中对应的那个key
    // 所以list要保存list到map的映射关系key，不能只保存value
    list<pair<int,int>> lis;
    //  key, value
    // value存储的是一个迭代器
    // 它指明了key在list中的位置，这样我们就不需要使用find函数来寻找key，这种做法能够降低时间复杂度
    map<int, list< pair<int,int> >::iterator> mp; 
    int cap;
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) { // get 得到对应的value，并将其移到队列首
        int val = -1;
        if(mp.count(key)) {
            val = mp[key] -> second;
            put(key,val);
        }
        return val;
    }
    // put：要移除很久未使用的map
    // 如果不存在：队列首加入，此时根据容量可能会挤掉尾元素。如存在：移动到队列首。
    void put(int key, int value) {
        if(mp.count(key)) { // 存在缓存, 之前的就不要了
            lis.erase(mp[key]);
        }
        else if(lis.size() == cap) {
            mp.erase(lis.back().first);
            lis.pop_back();
        }
        lis.push_front(make_pair(key,value));
        mp[key] = lis.begin();  
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */