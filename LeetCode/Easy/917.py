'''
@Author: zhaoyang.liang
@Github: https://github.com/LzyRapx
@Date: 2020-01-20 11:28:42
'''
class Solution:
    def reverseOnlyLetters(self, S: str) -> str:
        ans = ""
        if len(S) == 0:
            return ans
        hs = {}
        for i in range(len(S)):
            if S[i].isalpha():
                ans += S[i]
            else:
                hs[i] = S[i]
        
        ans = list(ans[::-1])
        for i in hs:
            ans.insert(i, hs[i])
            
        return ''.join(ans)
        
            
        