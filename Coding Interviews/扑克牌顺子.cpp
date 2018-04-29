class Solution {
public:
    // 题意： 从中抽出了5张牌,想测测自己的手气,看看能不能抽到顺子
    // 大小王可以看成任何数字
    int d[15];
    bool IsContinuous( vector<int> numbers ) {
        if(numbers.size() < 5) return false;
        memset(d,0,sizeof(d)); // 不 memset 就 gg
        d[0] = -5; // 可能 5 个 大小王 ？
        int maxx = -1;
        int minn = 14;
        for(int i = 0; i <=  numbers.size(); i++) {
            d[numbers[i]]++;
            if(numbers[i] == 0) {
                continue;
            }
            if(d[numbers[i]] > 1) {
                return false;
            }
            if(numbers[i] > maxx) {
                maxx = numbers[i];
            }
            if(numbers[i] < minn) {
                minn = numbers[i];
            }
        }
        if(maxx - minn < 5) {
            return true;
        }
        return false;
    }
};