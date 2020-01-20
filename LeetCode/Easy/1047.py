'''
@Author: zhaoyang.liang
@Github: https://github.com/LzyRapx
@Date: 2020-01-20 12:12:58
'''
class Solution:
    def removeDuplicates(self, S: str) -> str:
        ans = ""
        if len(S) == 0:
            return ans
        st = []
        for i in S:
            sz = len(st)
            if sz == 0:
                st.append(i)
            elif st[sz - 1] == i:
                st.pop()
            else:
                st.append(i)
        ans = ''.join(st)
        return ans
        
        