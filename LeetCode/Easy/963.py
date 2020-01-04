'''
@Descripttion: boring life && prevent age-related memory loss.
@Version: 1.0.0
@Author: zhaoyang.liang
@Github: https://github.com/LzyRapx
@Date: 2019-09-23 00:09:31
@LastEditors: zhaoyang.liang
@LastEditTime: 2019-09-23 00:09:31
'''

class Solution(object):
    # 对角线相等， 对角线平分
    def minAreaFreeRect(self, points):
        """
        :type points: List[List[int]]
        :rtype: float
        """
        N = len(points)
        d = collections.defaultdict(list)
        for i in range(N - 1):
            pi = points[i]
            for j in range(i + 1, N):
                pj = points[j]
                l = (pi[0] - pj[0]) ** 2 + (pi[1] - pj[1]) ** 2
                x = (pi[0] + pj[0]) / 2.0
                y = (pi[1] + pj[1]) / 2.0
                d[(l,x,y)].append((i, j))
        ans = float("inf")
        for l in d.values():
            sz = len(l)
            for i in range(sz - 1):
                p0, p2 = points[l[i][0]], points[l[i][1]]
                for j in range(i + 1, sz):
                    p1, p3 = points[l[j][0]], points[l[i][1]]
                    d1 = math.sqrt((p0[0] - p1[0]) ** 2 + (p0[1] - p1[1]) ** 2)
                    d2 = math.sqrt((p1[0] - p2[0]) ** 2 + (p1[1] - p2[1]) ** 2)
                    area = d1 * d2
                    ans = min(ans, area)
        return 0 if ans == float("inf") else ans
                    
        