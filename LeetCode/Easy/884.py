'''
@Author: zhaoyang.liang
@Github: https://github.com/LzyRapx
@Date: 2020-01-19 22:21:28
'''
class Solution:
    def uncommonFromSentences(self, A: str, B: str) -> List[str]:
        comb = A + " " + B
        mp  = {}
        words = comb.split(" ");
        for w in words:
            if w in mp:
                mp[w] += 1
            else:
                mp[w] = 1
                
        ans = []
        for w in words:
            if mp[w] == 1:
               ans.append(w) 
        return ans