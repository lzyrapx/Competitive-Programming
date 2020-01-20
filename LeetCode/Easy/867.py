'''
@Author: zhaoyang.liang
@Github: https://github.com/LzyRapx
@Date: 2020-01-19 18:02:56
'''
class Solution:
    def transpose(self, A: List[List[int]]) -> List[List[int]]:
        ans = []
        for i in range(len(A[0])):
            tmp = []
            for j in range(len(A)):
                tmp.append(A[j][i])
            ans.append(tmp)
        return ans
            
        