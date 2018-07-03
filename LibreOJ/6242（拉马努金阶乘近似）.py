#coding:utf8
from decimal import *
import decimal
import math
# c = decimal.getcontext().copy()
# c.prec = 10

getcontext().prec = 120
PI = Decimal('3.14159265358979323846264338327950288419716939937510582097494459230781640628\
6208998628034825342117067982148086513282306647093844609550582231725359408\
1284811174502841027019385211055596446229489549303819644288109756659334461\
2847564823378678316527120190914564856692346034861045432664821339360726024\
914127372458700660631558817488152092096282925409')
E = Decimal('2.71828182845904')

n, k = map(int, raw_input().split())

#拉马努金阶乘近似

# first_term = Decimal(math.sqrt(PI))
# second_term = Decimal((n / E )** n)
# third_term = Decimal((Decimal(8 * n ** 3 + 4 * n ** 2 + n) + (Decimal(1.0) / Decimal(30.0))) ** ((Decimal(1.0)) / Decimal(6.0)))
# ans = Decimal(first_term * second_term * third_term)

#print("ans=",ans)
#ans='{:.10f}'.format(ans) # 5f表示保留5位小数点的float型

ans = (PI.ln() / Decimal(2) + n * Decimal(n).ln() - n + (Decimal(8 * n ** 3 + 4 * n ** 2 + n) + Decimal(1.0) / Decimal(30.0)).ln() / Decimal(6.0)) / Decimal(10.0).ln()
xiaoshu = int(ans)
ans = Decimal(10) ** (ans - xiaoshu)
if n <= 20:
    ans = 1
    for i in xrange(n):
        ans *= i + 1
    ans /= 10. ** xiaoshu
ans = ('%.*f' % (k - 1, ans)).rstrip('0')
#print("ans=",ans)
if xiaoshu == 0:
    ans = ans.rstrip('.')
print '%se+%d' % (ans, xiaoshu)

