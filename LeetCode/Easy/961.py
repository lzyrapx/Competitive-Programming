'''
@Author: zhaoyang.liang
@Github: https://github.com/LzyRapx
@Date: 2020-01-20 23:03:49
'''
class Solution:
    def repeatedNTimes(self, A: List[int]) -> int:
        if not A:
            return 0
        mp = {}
        for i in range(len(A)):
            if A[i] in mp:
                mp[A[i]] += 1
            else:
                mp[A[i]] = 1
            if mp[A[i]] == len(A) // 2:
                return A[i]
        