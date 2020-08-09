class Solution {
public:
    // 按题目要求构造一个数组，满足格雷码的性质
    vector<int> circularPermutation(int n, int start) {
        vector<int>ans;
        ans.push_back(start);
        for(int i = 0; i < n; i++) {
            for(int j = ans.size() - 1; j >= 0; --j) {
                ans.push_back(ans[j] ^ (1 << i));
            }
        }
        return ans;
    }
    /*
    思路：
    比如n=3, start=2的情况：
    首先将2(010)加入数组
    将010最后一位翻转得到3(011)，此时数组为010,011
    将010与011的第二位翻转并逆序加入，得到010,011,001,000
    同上，得到010,011,001,000,100,101,111,110

    */
};