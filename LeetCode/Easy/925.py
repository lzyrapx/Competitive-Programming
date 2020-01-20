'''
@Author: zhaoyang.liang
@Github: https://github.com/LzyRapx
@Date: 2020-01-20 11:51:42
'''
class Solution:
    def isLongPressedName(self, name: str, typed: str) -> bool:
        if len(name) > len(typed):
            return False
        if name == typed:
            return True
        i = 0
        for c in name:
            while c != typed[i]:
                i += 1
                if i >= len(typed):
                    return False
            i += 1
            if i >= len(typed) and c != name[-1]:
                return False
        
        return True
                
            