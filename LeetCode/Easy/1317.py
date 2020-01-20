'''
@Author: zhaoyang.liang
@Github: https://github.com/LzyRapx
@Date: 2020-01-19 19:21:04
'''
class Solution:
    def getNoZeroIntegers(self, n: int) -> List[int]:
        if len(str(n)) == 1:
            return [1, n - 1]
        num = ""
        # 2 <= n <= 10^4
        for i in str(n)[1:]:
            if i == '0':
                num += '1'
            elif i == '1':
                num += '2'
            elif i == '2':
                num += '3'
            else:
                num += '1'
        
        return [int(num), n - int(num)]