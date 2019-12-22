/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-11-03 14:47:05
 */
// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        long long l = 1, r = n;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(guess(mid) > 0) {
                l = mid + 1;
            }
            else if(guess(mid) < 0){
                r = mid - 1;
            }
            else {
                return mid;
            }
        }
        return r;
    }
};