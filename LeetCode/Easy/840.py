'''
@Author: zhaoyang.liang
@Github: https://github.com/LzyRapx
@Date: 2020-01-19 13:05:22
'''
class Solution:
    def numMagicSquaresInside(self, grid: List[List[int]]) -> int:
        def magic(r,c):
            check = [grid[i][j] for i in range(r, r + 3) for j in range(c, c + 3) if 0 <= grid[i][j] <= 9]
            if len(set(check)) != 9: return False
            rsum = [sum(grid[i][c: c + 3]) for i in range(r, r + 3)]
            csum = [sum(grid[i][j] for i in range(r, r + 3)) for j in range(c, c + 3)]
            dsum = sum(grid[i][i - r + c] for i in range(r, r + 3))
            drsum = sum(grid[i][r + c + 2 - i] for i in range(r, r + 3))
            if len(set(rsum)) == len(set(csum)) == 1 and rsum[0] == csum[0] == dsum == drsum == 15:
                return True
            else:
                return False
            
        m, n, ans = len(grid), len(grid[0]), 0
        if m < 3 or n < 3: return 0;
        for i in range(m - 2):
            for j in range(n - 2):
                if grid[i + 1][j + 1] != 5:
                    continue
                if magic(i, j): ans += 1
        return ans