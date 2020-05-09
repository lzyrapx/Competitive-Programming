/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-05-09 15:32:36
 */
class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int left = 1;
        int right = m * n;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(check(mid, m, n, k)) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return left;
    }
    int check(int val, int m, int n, int k) {
        int cnt = 0;
        for(int i = 1; i <= m; i++) {
            if(i >  val) {
                break;
            }
            cnt += min(n, val / i);
        }
        return cnt >= k;
    }
};