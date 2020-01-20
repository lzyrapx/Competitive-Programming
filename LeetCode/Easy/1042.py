'''
@Author: zhaoyang.liang
@Github: https://github.com/LzyRapx
@Date: 2020-01-20 19:50:13
'''
class Solution:
    def gardenNoAdj(self, N: int, paths: List[List[int]]) -> List[int]:
        def solve(graden_idx, adj, ans):
            flower = [1,2,3,4]
            for nxt in adj[graden_idx]:
                cur = ans[nxt]
                if cur != 0 and cur in flower:
                    flower.remove(cur)
            return flower[0]
                
        adj = collections.defaultdict(list)
        ans = [0 for _ in range(N + 1)]
        for From,to in paths:
            adj[From].append(to)
            adj[to].append(From)
        
        for graden_idx in range(N + 1):
            ans[graden_idx] = solve(graden_idx, adj, ans)
        return ans[1:]
        
        