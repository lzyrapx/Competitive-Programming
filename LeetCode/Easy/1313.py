'''
@Author: zhaoyang.liang
@Github: https://github.com/LzyRapx
@Date: 2020-01-19 18:21:46
'''
class Solution:
    def decompressRLElist(self, nums: List[int]) -> List[int]:
        
        ans = []
        if len(nums) == 0:
            return ans
        
        for i in range(len(nums) // 2):
            a, b = nums[2*i], nums[2*i+1]
            for i in range(a):
                ans.append(b)
        return ans
        