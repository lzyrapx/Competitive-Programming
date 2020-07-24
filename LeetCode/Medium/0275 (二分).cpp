/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-07-24 22:49:45
 */ 
class Solution {
public:
    // 找到第一个 value[i] >= N - i
    int hIndex(vector<int>& citations) {
        int low = 0;
        int high = citations.size() - 1;
        int len = citations.size();
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(citations[mid] >= (len - mid)) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return len - low;
    }
};