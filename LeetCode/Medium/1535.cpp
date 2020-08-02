/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-08-02 17:03:48
 */ 
class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int cur = arr[0];
        int win = 0;
        for(int i = 1; i < arr.size(); i++) {
            if(arr[i] > cur) {
                cur = arr[i];
                win = 0;
            }
            win++;
            if(win == k) {
                break;
            }
        }
        return cur;
    }
};