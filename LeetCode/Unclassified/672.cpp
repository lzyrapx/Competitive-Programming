/*
 * @Descripttion: boring life && prevent age-related memory loss.
 * @Version: 1.0.0
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-09-16 00:32:07
 * @LastEditors: zhaoyang.liang
 * @LastEditTime: 2019-09-16 00:32:07
 */
class Solution {
public:
    // 0 <= n, m <= 1e3
    int flipLights(int n, int m) {
        n = (n <= 6) ? n : (n % 6 + 6);
        int start = (1 << n) - 1;
        unordered_set<int>se;
        queue<int>que{{start}};
        for(int i = 0; i < m; i++) {
            int len = que.size();
            se.clear();
            for(int k = 0; k < len; k++) {
                int state = que.front();
                que.pop();
                vector<int>next{flipAll(state, n), flipEven(state, n), flipOdd(state, n), flip3k1(state, n)};
                for(auto newState: next) {
                    if(se.count(newState)) continue;
                    que.push(newState);
                    se.insert(newState);
                }
            }
        }
        return que.size();
    }
    int flipAll(int newState, int n) {
        int s = (1 << n) - 1;
        return newState ^ s;
    }
    int flipEven(int newState, int n) {
        for(int i = 0; i < n; i += 2) {
            newState = newState ^ (1 << i);
        }
        return newState;
    }
    int flipOdd(int newState, int n) {
        for(int i = 1; i < n; i += 2) {
            newState = newState ^ (1 << i);
        }
        return newState;
    }
    int flip3k1(int newState, int n) {
        for (int i = 0; i < n; i += 3) {
            newState = newState ^ (1 << i);
        }
        return newState;
    }
};