'''
@Author: zhaoyang.liang
@Github: https://github.com/LzyRapx
@Date: 2020-01-30 18:06:19
'''
from functools import lru_cache
class Solution:
    def poorPigs(self, buckets: int, minutesToDie: int, minutesToTest: int) -> int:
        # f(n, t): the maximum number that can be recognized for n pigs with t tests
        # f(0, t) = 1
        # f(n, 0) = 1
        # f(n, t) = sum{c(n, k) * f(n-k, t-1) for all 0 <= k <= n}

        n_test = minutesToTest // minutesToDie
        
        @lru_cache(None)
        def f(n, t):
            if t == 0:
                return 1
            if n == 0:
                return 1
            
            res = 0
            comb = 1
            for k in range(n+1):
                res += comb * f(n-k, t-1)
                comb *= n-k
                comb //= k+1
            return res
        n = 0
        while f(n, n_test) < buckets:
            n += 1
        return n