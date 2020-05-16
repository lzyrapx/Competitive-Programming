/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-05-16 13:52:31
 */ 
class MyCalendarThree {
public:
    MyCalendarThree() {
        
    }
    map<int,int>mp;
    // 求最多有多少个重叠段
    // 也可以用线段树...
    int book(int start, int end) {
        mp[start]++;
        mp[end]--;
        int ans = 0;
        int sum = 0;
        for(auto& x: mp) {
            sum += x.second;
            if(sum > ans) {
                ans = sum;
            }
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */