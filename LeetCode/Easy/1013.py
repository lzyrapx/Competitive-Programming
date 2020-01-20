'''
@Author: zhaoyang.liang
@Github: https://github.com/LzyRapx
@Date: 2020-01-20 21:28:52
'''
class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        if len(A) <= 2:
            return False
        s = sum(A)
        if s % 3 != 0:
            return False
        target = s // 3
        
        preSum = [0 for _ in range(len(A))]
        for i in range(len(A)):
            if i == 0:
                preSum[i] = A[i]
            else:
                preSum[i] = preSum[i - 1] + A[i]
                
        for i in range(len(A) - 2):
            if preSum[i] == target:
                for j in range(i + 1, len(A) - 1):
                    if(preSum[j] - preSum[i] == target):
                        return True
        return False
        