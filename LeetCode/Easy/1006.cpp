/*
 * @Descripttion: boring life && prevent age-related memory loss.
 * @Version: 1.0.0
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-09-14 17:30:29
 * @LastEditors: zhaoyang.liang
 * @LastEditTime: 2019-09-14 17:30:29
 */
class Solution {
public:
    int clumsy(int N) { // 1 <= N <= 1e4
        if(N == 1) return 1;
        int ans = N;
        int op = 0;
        stack<int>sta;
        bool firstTime = true;
        for(int i = N - 1; i >= 1; --i) {
            switch(op) {
                case 0: // "*"
                    ans = ans * i;
                    if(i == 1) {
                        if(firstTime) {
                            sta.push(ans);
                            firstTime = false;
                        } 
                        else {
                            sta.push(-ans);
                        }
                    }
                    break;
                case 1: // "/"
                    ans = ans / i;
                    if(firstTime) {
                        sta.push(ans);
                        firstTime = false;
                    }else {
                        sta.push(-ans);
                    }
                    break;
                case 2: // "+"
                    sta.push(i);
                    break;
                case 3: // "-"
                    ans = i;
                    if(i == 1) {
                        sta.push(-ans);
                    }
                    break;
            }
            op = (op + 1) % 4;
        }
        int sum = 0;
        while(!sta.empty()) {
            sum += sta.top();
            sta.pop();
        }
        return sum;
    }
};