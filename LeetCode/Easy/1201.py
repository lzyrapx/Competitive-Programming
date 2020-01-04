'''
@Descripttion: boring life && prevent age-related memory loss.
@Version: 1.0.0
@Author: zhaoyang.liang
@Github: https://github.com/LzyRapx
@Date: 2019-09-27 01:46:10
@LastEditors: zhaoyang.liang
@LastEditTime: 2019-09-27 01:46:10
'''
class Solution(object):
    
    def nthUglyNumber(self, n, a, b, c):
        """
        :type n: int
        :type a: int
        :type b: int
        :type c: int
        :rtype: int
        """
        def gcd(a, b):
            if a % b == 0:
                 return b
            else:
                return gcd(b, a % b)
        
        def lcm2(a, b):
            return a * b // gcd(a, b)

        def lcm3(a, b, c):
            return lcm2(a, lcm2(b, c))
        
        low = 1
        high = 20 ** 9
        for i in range(100):
            mid = (low + high) // 2
            cnt = 0
            cnt += mid // a
            cnt += mid // b
            cnt += mid // c
            cnt -= mid // lcm2(a,b)
            cnt -= mid // lcm2(b,c)
            cnt -= mid // lcm2(a,c)
            cnt += mid // lcm3(a,b,c)
            if cnt == n:
                ans = mid
                high = high - 1
            if cnt < n:
                low = mid + 1
            else:
                high = mid - 1
        return ans
            
            