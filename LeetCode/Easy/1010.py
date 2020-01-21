'''
@Author: zhaoyang.liang
@Github: https://github.com/LzyRapx
@Date: 2020-01-20 22:04:13
'''
class Solution:
    def numPairsDivisibleBy60(self, time: List[int]) -> int:
        if len(time) == 0:
            return 0
        ans = 0
        mp = [0] * 60
        for t in time:
            ans += mp[(60 - t) % 60]
            mp[t % 60] += 1
        return ans