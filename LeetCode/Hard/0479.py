'''
@Author: zhaoyang.liang
@Github: https://github.com/LzyRapx
@Date: 2020-01-31 23:28:13
'''
class Solution:
    def largestPalindrome(self, n: int) -> int:
        if n == 1:
            return 9
        
        high = pow(10, n) - 1
        low = pow(10, n - 1)
        
        for i in range(high, low + 1, -1):
            # palindrome = 90 => 9009
            palindrome = int(str(i) + str(i)[::-1])
            
            for j in range(high, low + 1, -1):
                if palindrome // j > high:
                    break
                if palindrome % j == 0:
                    return palindrome % 1337
            
        