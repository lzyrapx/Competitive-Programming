'''
@Author: zhaoyang.liang
@Github: https://github.com/LzyRapx/Competitive-Programming/tree/master/LeetCode
@Date: 2020-03-08 01:17:09
'''
class Solution:
    # http://oeis.org/A327692
    def knightDialer(self, N: int) -> int:
        # 0, 1, 2, 3 ,4 ,5 ,6 ,7 ,8, 9
        reach = ((4, 6), (6, 8), (7, 9), (4, 8), (3, 9, 0), (), (1, 7, 0), (2, 6), (1, 3), (2, 4))
        M = [[0] * 10 for _ in range(N)]
        M[0] = [1]*10
        for step in range(1, N):
            for tile in range(10):
                for nxt in reach[tile]:
                    M[step][nxt] += M[step-1][tile]
        mod = 10 ** 9 + 7
        return sum(M[-1]) % mod

class Solution(object):
    def knightDialer(self, N):
        """
        :type N: int
        :rtype: int
        """
        dp = [0] * (N + 6)
        dp[1] = 10
        dp[2] = 20
        dp[3] = 46
        dp[4] = 104
        dp[5] = 240
        dp[6] = 544
        mod = 10 ** 9 + 7
        for i in range(6, N + 1):
            dp[i] = 6 * dp[i - 2] - 4 * dp[i - 4]
        return dp[N] % mod
           