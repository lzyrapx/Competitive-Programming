/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-08-02 15:24:53
 */ 
class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int cnt = 0;
        for(int i = 0; i < arr.size(); i++) {
            for(int j = i + 1; j < arr.size(); j++) {
                for(int k = j + 1; k < arr.size(); k++) {
                    if(abs(arr[i] - arr[j]) <= a && abs(arr[j] - arr[k]) <= b && abs(arr[i] -arr[k]) <= c) {
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};