'''
@Author: zhaoyang.liang
@Github: https://github.com/LzyRapx
@Date: 2020-01-19 13:26:07
'''
class Solution:
    def backspaceCompare(self, S: str, T: str) -> bool:
        st1 = []
        if S[0] != '#':
            st1.append(S[0])
        for i in range(1, len(S)):
            if S[i] == '#' and len(st1) > 0:
                st1.pop()
            elif 'a' <= S[i] <= 'z': 
                st1.append(S[i])
        
        st2 = []
        if T[0] != '#':
            st2.append(T[0])
        for j in range(1,len(T)):
            if T[j] == '#' and len(st2) > 0:
                st2.pop()
            elif 'a' <= T[j] <= 'z':
                st2.append(T[j])
        print(st1, st2)
        if st1 == st2:
            return True
        else:
            return False