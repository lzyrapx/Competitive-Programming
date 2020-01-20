'''
@Author: zhaoyang.liang
@Github: https://github.com/LzyRapx
@Date: 2020-01-19 22:05:58
'''
class Solution:
    def fairCandySwap(self, A: List[int], B: List[int]) -> List[int]:
        s1 = sum(A)
        s2 = sum(B)
        B = set(B)
        for a in A:
            b = (s2 - s1 + 2 * a) // 2
            if b in B:
                return [a,b]
        