class Solution {
public:
    //https://www.cnblogs.com/grandyang/p/6648557.html
    int findMinMoves(vector<int>& machines) {
        if(machines.size() == 0) return 0;
        int sum = accumulate(machines.begin(),machines.end(),0);
        if(sum % machines.size() != 0 ) return -1;
        int target = sum / machines.size();
        int ans = 0;
        int tmp = 0;
        for(int i = 0; i < machines.size(); i++)
        {
            tmp += machines[i] -  target; //machines[i] -  target : 当前洗衣机需要移动的衣服数
            ans = max(ans , max(machines[i] - target, abs(tmp))); //移动至少需要的次数就是差值数组中出现的绝对值最大的数字
        }
        return ans;
    }
};