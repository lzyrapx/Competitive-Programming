#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 50010;
const int mod = 1e9 + 7;
int a[maxn];
pair<int,int> f[maxn]; // LIS length, count
int n;
int id[maxn];

// http://www.51nod.com/onlineJudge/questionCode.html#!problemId=1376
// 求 A{x1,x2,....，xn}的 LIS有多少个
// LIS : 二维偏序问题,一维下标,二维数值。 cdq分治复杂度是O(nloglogn)

void getmax(pair<int,int> &x, pair<int,int> y)
{
  if(x.first < y. first) x = y;
  else if(x.first == y.first) {
    x.second += y.second;
    if( x.second >= mod) {
      x.second -= mod;
    }
  }
}

bool cmp(int x, int y)
{
  if(a[x] != a[y]) return a[x] < a[y];
  return x > y;
}

void cdq(int l, int r)
{
  if(l >= r) return ;
  int mid = (l + r) >> 1;
  cdq(l, mid); // 先递归求解区间左半边

  for(int i = l; i <= r; i++) {
    id[i] = i;
  }
  sort(id + l, id + r + 1, cmp);
  // for(int i = l; i <= r; i++) {
  //   std::cout << "id = " << id[i] << " " ;
  // }
  // std::cout << '\n';
  
  pair<int,int> maxf(0,0);
  
  // 单独处理左半边和处理左半边对于右半边的影响，就叫 CDQ分治
  // 用左边的值更新右边，相当于处理跨越区间中点的情况
  
  // std::cout << "mid = " << mid << '\n';
  for(int i = l; i <= r; i++) {
    int idx = id[i]; // 按 a[i] 从小到大排序的下标
    if(idx <= mid)  {
      getmax(maxf,f[idx]);
    }
    else{
      pair<int,int> cur = maxf;
      cur.first++;
      getmax(f[idx],cur);
    }
  }
  // 递归求解区间右半边
  cdq(mid + 1, r);
}
int main(int argc, char const *argv[]) {
  std::cin >> n;
  for(int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for(int i = 1; i <= n; i++) {
    f[i] = make_pair(1,1); // 初始化
  }
  cdq(1,n);

  pair<int,int> ans(0,0);
  for(int i = 1; i <= n; i++) {
    getmax(ans,f[i]); // 统计并更新数量
  }
  std::cout << ans.second << '\n';
  return 0;
}
