'''
@Author: zhaoyang.liang
@Github: https://github.com/LzyRapx
@Date: 2020-01-21 12:11:14
'''
class Solution:
    def addToArrayForm(self, A: List[int], K: int) -> List[int]:
        s = ""
        for c in A:
            s = s + str(c)
        num = int(s) + K
        num_str = str(num)
        ans = []
        for c in num_str:
            ans.append(c)
        return ans
        