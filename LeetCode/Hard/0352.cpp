/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-01-29 14:55:39
 */
class SummaryRanges {
public:
    /** Initialize your data structure here. */
    map<int,int>mp;
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        if(mp.count(val)) {
            return;
        }
        mp[val] = val;
        int minn = val, maxx = val;
        if(mp.count(val - 1)) {
            minn = mp[val - 1];
        }
        if(mp.count(val + 1)) {
            maxx = mp[val + 1];
        }
        mp[minn] = maxx;
        mp[maxx] = minn;
    }
    // 新加进来的数字如果遇到连续区间就合并
    vector<vector<int>> getIntervals() {
        vector<vector<int>>ans;
        auto it = mp.begin();
        while(it != mp.end()) {
            ans.push_back({it -> first, it -> second});
            it = mp.upper_bound(it -> second);
        }
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */