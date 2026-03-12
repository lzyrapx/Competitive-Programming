#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 200010;
const int mod = 1e9 + 7;

// http://acm.hdu.edu.cn/showproblem.php?pid=5618
// solution :  O(n*logn*logn)

int n,k;

int s[maxn];
int ans[maxn];

struct Query
{
  int x,y,z;
  int ans,cnt;
  int id;
  bool operator == (const Query& a)const {
    return x == a.x && y == a.y && z == a.z;
  }
}a[maxn];

inline int lowbit(int x)
{
  return x&(-x);
}
void update(int pos,int val)
{
  while(pos <= k) {
    s[pos] += val;
    pos += lowbit(pos);
  }
}
int query(int pos)
{
  int res = 0;
  while(pos > 0) {
    res += s[pos];
    pos -= lowbit(pos);
  }
  return res;
}

bool cmpy(Query a, Query b)
{
  if(a.y == b.y) return a.z < b.z;
  return a.y < b.y;
}

void cdq(int l, int r)
{
  if(l >= r) return;
  int mid = (l + r) >> 1;
  cdq(l, mid);
  cdq(mid + 1, r);
  // 每次把平分的两个数组进行排序
  sort(a + l, a  +  mid + 1, cmpy);
  sort(a + mid + 1, a + r + 1, cmpy);

  // 然后扫一遍.
  // 因为排过序.
  // 所以如果对于[low,mid]里的 i 对[mid+1,r]里的 j 有贡献的话，
  // 那么它对 j+1 也是有贡献的

  // 单独处理前一部分和处理前一部分对后一部分的影响，就是 CDQ 分治
  int low = l, high = mid + 1;
  for(high = mid + 1; high <= r; high ++)
  {
    while(low <= mid && a[low].y <= a[high].y)
    {
      update(a[low].z,1);
      low++;
    }
    // 统计树状数组中所有下标小于等于 q.z 的值之和累加到 q.ans中
    a[high].ans += query(a[high].z);
  }
  // 最后要去掉[l,low-1]的贡献, 相当于撤销操作
  // std::cout << "low = " << low << '\n';
  for(int i = l; i < low; i++) {
    update(a[i].z ,-1);
  }
}
bool cmpx(Query a, Query b)
{
   if(a.x == b.x && a.y == b.y) return a.z < b.z;
   else if(a.x == b.x) return a.y < b.y;
   return a.x < b.x;
}
int main(int argc, char const *argv[]) {
  // freopen("in.txt","r",stdin);
  int t;
  scanf("%d", &t);
  while(t--)
  {
    memset(s,0,sizeof(s));
    memset(a,0,sizeof(a));
    memset(ans,0,sizeof(ans));
    scanf("%d",&n);
    for(int i = 1; i <= n; i++) {
      scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].z);
    }
    k = 100010;
    for(int i = 1; i <= n; i++) {
      a[i].id = i;
    }
    sort(a + 1, a + n + 1, cmpx); // 排序去掉其中一维
    cdq(1,n);
    // for(int i = 1; i <= n; i++) {
    //   std::cout << "ans = " << a[i].ans << '\n';
    // }
    int i = 1;
    while(i <= n)
    {
      int j = i + 1;
      int tmp = a[i].ans;
      while(j <= n && a[i].x == a[j].x && a[i].y == a[j].y && a[i].z == a[j].z) // 重载一下符号也行
      {
        tmp = max(a[j].ans,tmp);
        j++;
      }
      for(int k = i; k < j; k++) {
        ans[a[k].id] = tmp;
      }
      i = j;
    }

    for(int i = 1; i <= n; i++) {
      std::cout << ans[i] << '\n';
    }
  }
  return 0;
}
