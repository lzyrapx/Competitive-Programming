'''
@Author: zhaoyang.liang
@Github: https://github.com/LzyRapx
@Date: 2020-01-20 22:51:56
'''
class Solution:
    def largestSumAfterKNegations(self, A: List[int], K: int) -> int:
        if len(A) == 0:
            return 0
        if K == 0:
            return sum(A)
        heapq.heapify(A)
        for _ in range(K):
            cur = heapq.heappop(A)
            heapq.heappush(A, -cur)
        return sum(A)