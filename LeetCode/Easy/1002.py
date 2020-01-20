'''
@Author: zhaoyang.liang
@Github: https://github.com/LzyRapx
@Date: 2020-01-20 20:45:46
'''
class Solution:
    def commonChars(self, A: List[str]) -> List[str]:
        from collections import Counter
        word = Counter(A[0])
        for i in range(1, len(A)):
            word = word & Counter(A[i])
            
        print(word)
        ans = []
        for i in word.keys():
            if word[i] > 1:
                for k in range(word[i]):
                    ans.append(i)
            else:
                ans.append(i)
        return ans
        