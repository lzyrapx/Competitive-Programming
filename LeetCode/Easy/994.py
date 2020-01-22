'''
@Author: zhaoyang.liang
@Github: https://github.com/LzyRapx
@Date: 2020-01-21 13:33:51
'''
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        queue = []
        vis = set()
        mp = set()
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 2:
                    mp.add((i,j))
        queue.append(mp)
        ans = -1 if mp else 0
        while len(queue) > 0:
            tmp = set()
            cur_node = queue.pop()
            vis.update(cur_node)
            if not cur_node:
                break
            for i, j in cur_node:
                grid[i][j] = 2
                for x, y in [(i + 1, j), (i - 1, j), (i, j + 1), (i, j - 1)]:
                    if 0 <= x < len(grid) and 0 <= y < len(grid[0]):
                        if (x, y) not in vis and grid[x][y] != 0:
                            tmp.add((x,y))
            ans += 1
            queue.append(tmp)
        
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    return -1
        return ans
        