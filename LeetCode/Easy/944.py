'''
@Author: zhaoyang.liang
@Github: https://github.com/LzyRapx
@Date: 2020-01-21 14:19:25
'''
class Solution:
    def minDeletionSize(self, A: List[str]) -> int:
        ans = []
        for i in range(len(A) - 1):
            for j in range(len(A[0])):
                if A[i][j] > A[i + 1][j]:
                    if j not in ans:
                        ans.append(j)
        return len(ans)
        