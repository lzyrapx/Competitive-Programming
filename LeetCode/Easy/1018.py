'''
@Author: zhaoyang.liang
@Github: https://github.com/LzyRapx
@Date: 2020-01-20 20:58:51
'''
class Solution:
    def prefixesDivBy5(self, A: List[int]) -> List[bool]:
        if len(A) == 0:
            return A
        num = 0
        ans = []
        for i in range(len(A)):
            num = num + (1 << (len(A) - 1 - i)) * A[i]
            # print(num)
            if num % 5 == 0:
                ans.append(True)
            else:
                ans.append(False)
        return ans
            
        