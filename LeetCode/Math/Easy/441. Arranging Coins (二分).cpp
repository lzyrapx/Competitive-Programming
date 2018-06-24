class Solution {
public:
    int arrangeCoins(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        long long low = 1, high = n;
        while(low <= high)
        {
            long long mid = (low + high) >> 1;
            if(mid * (mid + 1) / 2 == n) return mid;
            else if(mid * (mid + 1) / 2 < n) low = mid + 1;
            else high = mid - 1;
        }
        return high;
    }
};