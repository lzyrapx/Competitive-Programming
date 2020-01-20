'''
@Author: zhaoyang.liang
@Github: https://github.com/LzyRapx
@Date: 2020-01-19 22:45:13
'''
class Solution:
    def isMonotonic(self, A: List[int]) -> bool:
        if len(A) == 1:
            return True
        inc = 0
        des = 0
        for i in range(len(A) - 1):
            if A[i] == A[i + 1]: continue
            if A[i] > A[i + 1]:
                des = 1
            else:
                inc = 1
        if inc == des == 1:
            return False
        return True