'''
@Author: zhaoyang.liang
@Github: https://github.com/LzyRapx
@Date: 2020-01-21 14:05:22
'''
class Solution:
    def numMovesStones(self, a: int, b: int, c: int) -> List[int]:
        
        # a != b, b != c, c != a
        arr = [a,b,c]
        arr = sorted(arr)
        dis1 = arr[1] - arr[0] - 1
        dis2 = arr[2] - arr[1] - 1
        if dis1 == 0 and dis2 == 0:
            res = [0]
        elif dis1 == 0 or dis2 == 0:
            res = [1]
        elif dis1 == 1 or dis2 == 1:
            res = [1]
        else:
            res = [2]
        res.append(dis1 + dis2)
        return res
        