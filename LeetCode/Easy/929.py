'''
@Author: zhaoyang.liang
@Github: https://github.com/LzyRapx
@Date: 2020-01-20 12:03:33
'''
class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        if len(emails) == 0:
            return 0
        ans = set()
        for e in emails:
            local, domain = e.split('@')
            local = local.split("+")[0]
            tmp = local.split(".")
            local = ''.join(tmp)
            real_email= local+"@"+domain
            ans.add(real_email)
        return len(ans)
        