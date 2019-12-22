/*
 * @Descripttion: Prevent age-related memory loss.
 * @version: 1.0.0
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-09-11 01:10:05
 * @LastEditors: zhaoyang.liang
 * @LastEditTime: 2019-09-11 01:10:05
 */
class Solution {
public:
    bool isPrime(int n) {
        for(int i = 2; i * i <= n; i++) {
            if(n % i == 0) return false; 
        }
        return true;
    }
    const int mod = 1e9 + 7;
    int numPrimeArrangements(int n) {
        if(n <= 1) return 1;
        int primeNum = 0;
        for(int i = 2; i <= n; i++) {
            if(isPrime(i)) {
                primeNum++;
            }
        }
        long long ans = 1;
        for(int i = 1; i <= primeNum; i++) {
            ans = ans * i % mod;
        }
        for(int i = 1; i <= n - primeNum; i++) {
            ans = ans * i % mod;
        }
        return ans;
    }
};