/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-01-05 13:28:27
 */
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        queue<int>que;
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] == 0) {
                que.push(0);
            }
            if(!que.empty()) {
                que.push(arr[i]);
                arr[i] = que.front();
                que.pop();
            }
        }
    }
};