'''
@Author: zhaoyang.liang
@Github: https://github.com/LzyRapx
@Date: 2020-01-20 14:19:42
'''
class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        if len(stones) == 0:
            return 0
        heap = []
        for s in stones:
            heapq.heappush(heap,-s)
        while len(heap) > 1:
            t1 = heapq.heappop(heap)
            t2 = heapq.heappop(heap)
            if t1 == t2:
                continue
            else:
                heapq.heappush(heap, -abs(t1 - t2))
        if len(heap) > 0:
            return -heap[0]
        else: return 0
        