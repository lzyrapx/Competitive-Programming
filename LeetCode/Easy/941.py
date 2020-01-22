'''
@Author: zhaoyang.liang
@Github: https://github.com/LzyRapx
@Date: 2020-01-21 12:21:15
'''
class Solution:
    def validMountainArray(self, A: List[int]) -> bool:
        if len(A) <= 2:
            return False
        ok = 0
        if A[0] > A[1]:
            return False
        
        for i in range(len(A) - 1):
            if A[i] < A[i + 1] and ok == 1:
                return False
            if A[i] == A[i + 1]:
                return False
            if A[i] > A[i + 1]:
                ok = 1
        if ok:
            return True
        else:
            return False
                
        