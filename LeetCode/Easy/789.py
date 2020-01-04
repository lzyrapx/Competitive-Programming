'''
@Descripttion: boring life && prevent age-related memory loss.
@Version: 1.0.0
@Author: zhaoyang.liang
@Github: https://github.com/LzyRapx
@Date: 2019-09-25 00:27:36
@LastEditors: zhaoyang.liang
@LastEditTime: 2019-09-25 00:27:36
'''
class Solution(object):
    def escapeGhosts(self, ghosts, target):
        """
        :type ghosts: List[List[int]]
        :type target: List[int]
        :rtype: bool
        """
        # the distance of player to target
        dis = abs(target[0]) + abs(target[1])
        for x, y in ghosts:
            if abs(x - target[0]) + abs(y - target[1]) <= dis:
                return False
        return True