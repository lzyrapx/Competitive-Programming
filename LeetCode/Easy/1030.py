'''
@Author: zhaoyang.liang
@Github: https://github.com/LzyRapx
@Date: 2020-01-20 21:48:54
'''
class Solution:
    def allCellsDistOrder(self, R: int, C: int, r0: int, c0: int) -> List[List[int]]:
        ans = [[r,c] for r in range(R) for c in range(C)]
        return sorted(ans, key=lambda x: abs(x[0] - r0) + abs(x[1] - c0))