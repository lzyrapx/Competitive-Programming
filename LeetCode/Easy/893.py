'''
@Author: zhaoyang.liang
@Github: https://github.com/LzyRapx
@Date: 2020-01-19 23:10:46
'''
from collections import Counter 
class Solution:
    def numSpecialEquivGroups(self, A: List[str]) -> int:
        se = set()
        for a in A:
            x = Counter(a[::2])
            y = Counter(a[1::2])
            x = tuple(sorted(x.items()))
            y = tuple(sorted(y.items()))
            se.add((x,y))
        return len(se)
        