'''
@Author: zhaoyang.liang
@Github: https://github.com/LzyRapx
@Date: 2020-01-21 14:38:38
'''
class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        def check(dx, dy, m, n):
            i, j = m, n
            while 0 <= i < 8 and 0 <= j < 8:
                if board[i][j] not in ('p', 'B'):
                    i = i + dx
                    j = j + dy
                else:
                    if board[i][j] == 'p':
                        return True
                    return False
            return False
        
        m, n = 0, 0
        for i in range(8):
            for j in range(8):
                if board[i][j] == 'R':
                    m, n = i, j
        ans = 0        
        for dir in [(0,1),(0,-1),(1,0),(-1,0)]:
            ans += check(dir[0], dir[1], m, n)
        return ans
        