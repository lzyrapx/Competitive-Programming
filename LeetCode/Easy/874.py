'''
@Author: zhaoyang.liang
@Github: https://github.com/LzyRapx
@Date: 2020-01-19 20:23:46
'''
class Solution:
    def robotSim(self, commands: List[int], obstacles: List[List[int]]) -> int:
        obst = {tuple(i) for i in obstacles}
        ans = 0
        x, y, dx, dy = 0, 0, 0, 1
        # north: 0, 1
        # south: 0, -1
        # east: 1, 0
        # west: -1, 0
        for i in commands:
            if i == -1:
                dx, dy = dy, -dx
            elif i == -2:
                dx, dy = -dy, dx
            else:
                while i:
                    _x, _y = x + dx, y + dy
                    if (_x, _y) not in obst:
                        x, y, ans = _x, _y, max(ans, _x * _x + _y * _y)
                    i -= 1
        return ans
        