/*
 * @Descripttion: boring life && prevent age-related memory loss.
 * @Version: 1.0.0
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-09-14 13:50:33
 * @LastEditors: zhaoyang.liang
 * @LastEditTime: 2019-09-14 13:50:33
 */
class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        int minV = -1;
        int maxV = 0;
        int modeV = 0;
        double meanV = 0, medianV = 0;
        int num = 0;
        long long sum = 0;
        int n = count.size();
        for(int i = 0; i < n; i++) {
            int v = count[i];
            num += v;
            sum += v * i;
            if(minV < 0 && v > 0) {
                minV = i;
            }
            if(v > 0) { // maxinum index
                maxV = i;
            }
            if(v > count[modeV]) {
                modeV = i; 
            }
        }
        meanV = sum * 1.0 / num; // average
        double firstV = 0, secondV = 0;
        int midPos = num / 2;
        int tmp = 0;
        for(int i = 0; i < n; i++) {
            int v = count[i];
            if(midPos > tmp && midPos <= tmp + v) {
                firstV = i;
            }
            if(midPos + 1 > tmp && midPos + 1 <= tmp + v) {
                secondV = i;
            }
            tmp += v;
        }
        if(num % 2 == 1) {
            medianV = firstV;
        } else {
            medianV = (firstV + secondV) / 2;
        }
        return {minV, maxV, meanV, medianV, modeV};
    }
};