/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-01-28 17:52:37
 */
class Solution {
public:
    vector<int> tree;
    int n,m;
    int lowbit(int x){
        return x & (-x);
    }
    void update(int idx, int x)
    {
        while(idx <= m)
        {
            tree[idx] += x;
            idx += lowbit(idx);
        }
    } 
    int getSum(int x)
    {
        // lower_bound/upper_bound 找不到合法解时 x = m + 1
        if(x == m + 1) return 0;
        int res = 0;
        while(x)
        {
            res += tree[x];
            x -= lowbit(x);
        }
        return res;
    }
    //  lower <= sum[i] - sum[j] <= upper
    //  => sum[i] - upper =< sum[j] <= sum[i] - lower
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        if(n == 0) {
            return 0;
        }
        vector<long long> preSum(n + 1,0);
        for(int i = 0 ; i < n ; i ++) {
            preSum[i + 1] = preSum[i] + nums[i];
        }
        vector<long long> temp = preSum;
        sort(temp.begin(),temp.end());
        temp.erase(unique(temp.begin(),temp.end()),temp.end());
        m = temp.size();
        tree = vector<int>(m + 1,0);
        unordered_map<int,int> hash,hash_lower,hash_upper;
        for(int i = 0 ; i < m ; i ++)
        {
            // cout << "t = "<< temp[i] << endl;
            hash[temp[i]] = i + 1;
            hash_lower[temp[i]] = lower_bound(temp.begin(),temp.end(),temp[i] - upper) - temp.begin();
            hash_upper[temp[i]] = upper_bound(temp.begin(),temp.end(),temp[i] - lower) - temp.begin();
        }
        int res = 0;
        update(hash[0],1);
        for(int i = 1 ; i <= n ; i ++)
        {
            res += getSum(hash_upper[preSum[i]]) - getSum(hash_lower[preSum[i]]);
            update(hash[preSum[i]],1);
        }
        return res;
    }
};