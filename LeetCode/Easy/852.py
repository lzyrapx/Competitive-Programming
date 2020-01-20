'''
@Author: zhaoyang.liang
@Github: https://github.com/LzyRapx
@Date: 2020-01-19 13:48:57
'''
class Solution:
    # return any i
    def peakIndexInMountainArray(self, A: List[int]) -> int:
        low, high = 0, len(A) - 1
        while low < high:
            mid = (low + high) // 2
            if A[mid] < A[mid + 1]:
                low = mid + 1
            else:
                high = mid
        return low