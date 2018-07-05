class Solution {
public:
    /*
    题意：
    给定一个char数组，代表CPU需要做的任务，包含A-Z，不用考虑顺序，每个任务能在1个单位完成。
    但是规定一个非负整数n代表两个相同任务之间需要至少n个时间单位。求最少数量的时间单位完成所有任务。
    思路：
    先要找到最大的任务个数cnt，若总任务类数>=n,则时间至少为(cnt-1)*（n+1）+ 最大值类数; 否则就是总任务类数。
    */
    int leastInterval(vector<char>& tasks, int n) {
        if(tasks.size() == 0) return 0;
        map<char,int>mp;
        int cnt = 0;
        for(auto x : tasks)
        {
            mp[x]++;
            cnt = max(cnt, mp[x]);  // maximum required cpu for most frequently appearing task
        }
        // after placing most frequent task at first place, there still are cnt - 1 instances, which must be 
        // spaced at n+1 distance
        // this requires (cnt - 1) * (n + 1) spaces (this did not count space for one instance of most frequent task)
        // 对于样例：A -> B -> idle -> A -> B -> idle -> A -> B.
        // ans = 6 就是先计算 A -> B -> idle -> ？ -> B -> idle -> A -> ？.
        int ans = (cnt - 1) * (n + 1);
        for(auto x : mp)
        {
            if(x.second == cnt) ans++; // 例如：添加 样例中的 "？" ，两个"？"
        }
        // if number of slots in tasks array are already large enough to accomodate this arrangement
        return max((int)tasks.size(), ans);
    }
};