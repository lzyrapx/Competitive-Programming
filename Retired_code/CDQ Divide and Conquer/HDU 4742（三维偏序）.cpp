#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100010;
const int mod = (1 << 30);

// http://acm.hdu.edu.cn/showproblem.php?pid=4742
// solution :  O(n*logn*logn)
// 其实是个三维 LIS
int n,k;

int s[maxn];

struct Query
{
  int x,y,z;
  int ans,cnt;
  int id;
}a[maxn],q[maxn];

struct DP
{
  int len,cnt;
  DP(){}
  DP(int _len, int _cnt):len(_len),cnt(_cnt){}
}dp[maxn],p[maxn];

inline int lowbit(int x)
{
  return x&(-x);
}

void getmax(DP &dp1, DP &dp2)
{
  if(dp1.len < dp2.len) dp1 = dp2;
  else if(dp1.len == dp2.len) {
    dp1.cnt += dp2.cnt % mod;
    dp1.cnt  %= mod;
  }
}
int idx;
void update(int pos,DP &dp1)
{
  while(pos <= k) {
    getmax(p[pos],dp1);
    pos += lowbit(pos);
  }
}
DP query(int pos)
{
  DP res = DP(0,0);
  while(pos > 0) {
    getmax(res,p[pos]);
    pos -= lowbit(pos);
  }
  return res;
}

void Clear(int pos)
{
  while(pos <= k)
  {
    p[pos] = DP(0,0);
    pos += lowbit(pos);
  }
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
  for(int i = l; i <= r; i++) {
    q[i] = a[i];
    q[i].x = 0;
  }
  sort(q+l,q+r+1,cmpy);
  for(int i = l; i <= r; i++) {
    if(q[i].id <= mid) { // 单独处理左半边
      update(q[i].z,dp[q[i].id]);
    }
    else{ // 再处理左半边对右半边的影响
      DP cur = query(q[i].z);
      cur.len++;
      getmax(dp[q[i].id],cur);
    }
  }
  for(int i = l; i <= r; i++) {
    if(q[i].id <= mid) {
      Clear(q[i].z);
    }
  }
  cdq(mid + 1, r);
}
bool cmpx(Query a, Query b)
{
   if(a.x == b.x && a.y == b.y) return a.z < b.z;
   else if(a.x == b.x) return a.y < b.y;
   return a.x < b.x;
}
int vec[maxn];
int main(int argc, char const *argv[]) {
  // freopen("in.txt","r",stdin);
  int t;
  scanf("%d", &t);
  while(t--)
  {
    memset(s,0,sizeof(s));
    memset(a,0,sizeof(a));
    memset(q,0,sizeof(q));
    memset(dp,0,sizeof(dp));
    scanf("%d",&n);
    for(int i = 1; i <= n; i++) {
      scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].z);
      vec[i - 1] = a[i].z;
    }
    k = 100010;
    sort(a + 1, a + n + 1, cmpx); // 排序去掉其中一维
    sort(vec,vec+n);

    idx = unique(vec,vec+n) - vec;
    for(int i  = 1; i <= n; i++) {
      a[i].z = lower_bound(vec,vec + idx,a[i].z) - vec + 1;
      a[i].id = i;
      dp[i] = DP(1,1);
     }
    cdq(1,n);
    DP ans = DP(0,0);
    for(int i = 1; i <= n; i++) {
      getmax(ans,dp[i]);
    }
    printf("%d %d\n", ans.len, ans.cnt % mod);
  }
  return 0;
}
