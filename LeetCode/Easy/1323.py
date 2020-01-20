'''
@Author: zhaoyang.liang
@Github: https://github.com/LzyRapx
@Date: 2020-01-19 17:47:58
'''
class Solution:
    def maximum69Number (self, num: int) -> int:
        nums = str(num)
        ans = ""
        one = 0
        for i in range(len(nums)):
            if nums[i] == "6" and one == 0:
                ans  = ans + "9"
                one = 1
            else:
                ans = ans + nums[i]
        return int(ans)