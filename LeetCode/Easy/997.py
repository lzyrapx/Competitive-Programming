'''
@Author: zhaoyang.liang
@Github: https://github.com/LzyRapx
@Date: 2020-01-20 15:04:00
'''
class Solution:
    def findJudge(self, N: int, trust: List[List[int]]) -> int:
        if len(trust) == 0:
            return 1
        ind = {}
        outd = {}
        for i in trust:
            if i[0] in outd:
                outd[i[0]] += 1
            else: 
                outd[i[0]] = 1
                
            if i[1] in ind:
                ind[i[1]] += 1
            else:
                ind[i[1]] = 1
                
        for i in range(1,N + 1):
            if i in ind:
                if ind[i] == N - 1 and i not in outd:
                    return i
        return -1
        