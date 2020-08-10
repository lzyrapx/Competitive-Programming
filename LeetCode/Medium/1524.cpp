class Solution {
public:
    // 给你一个数组arr，问你连续子数组的和是奇数的数量是多少，对1e9+7取模
    // 1 <= arr.length <= 10^5
    // 思路：奇数-偶数=奇数，偶数-奇数=奇数
    const int mod = 1e9 + 7;
    int numOfSubarrays(vector<int>& arr) {
        if(arr.size() == 0) {
            return 0;
        }
        long long ans = 0;
        long long even = 1; //前缀和为0也算偶数
        long long odd = 0;
        long long sum = 0;
        for(int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            if(sum % 2 == 0) {
                ans += odd;
                ans %= mod;
                even++;
            }
            else {
                ans += even;
                ans %= mod;
                odd++;
            }
        }
        return ans % mod;
    }
};