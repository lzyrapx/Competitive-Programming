'''
@Author: zhaoyang.liang
@Github: https://github.com/LzyRapx
@Date: 2020-01-20 20:16:51
'''
class Solution:
    def reorderLogFiles(self, logs: List[str]) -> List[str]:
        if len(logs) == 0:
            return logs
        digit_logs = []
        letter_logs = []
        for log in logs:
            l = log.split(" ", 1)
            if '0' <= l[1][0] <= '9':
                digit_logs.append(log)
            else:
                letter_logs.append(log)
                
        letter_logs.sort(key=lambda s: s.split()[0])
        letter_logs.sort(key=lambda s: s.split()[1:])
        
        # print(letter_logs)
        
        letter_logs.extend(digit_logs)
        
        return letter_logs
        
                