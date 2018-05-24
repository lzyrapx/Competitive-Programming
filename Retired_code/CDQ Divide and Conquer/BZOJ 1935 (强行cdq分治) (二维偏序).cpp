#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 505000;
const int mod = (1 << 30);

// https://www.lydsy.com/JudgeOnline/problem.php?id=1935
// 强行 cdq分治
int k;
struct Query{
  int type,x,y,op,id;
  Query(){}
  Query(int _type, int _x, int _y, int _op, int _id){
    type = _type, x = _x, y = _y, op = _op, id = _id;
  }
  bool operator <(const Query b) const{
    return x < b.x || (x == b.x && type < b.type);
  }
}q[maxn * 5],tmp[maxn * 5]; // 注意数组大小

int s[maxn * 5];

inline int lowbit(int x)
{
  return x&(-x);
}
void update(int pos, int val)
{
  while(pos <= k)
  {
    s[pos] += val;
    pos += lowbit(pos);
  }
}
int query(int pos)
{
  int res = 0;
  while(pos > 0)
  {
    res += s[pos];
    pos -= lowbit(pos);
  }
  return res;
}

void Clear(int pos)
{
  while(pos <= k && s[pos] != 0)
  {
    s[pos] = 0;
    pos += lowbit(pos);
  }
}
// bool operator <(Query a,Query b){
//     return a.x < b.x|| (a.x == b.x && a.type < b.type);
// }

int ans[maxn];
void cdq(int l, int r)
{
  if(l >= r) return ;
  int mid = (l + r) >> 1;
  cdq(l,mid);
  cdq(mid + 1,r);

  int low = l; int high = mid + 1;
  int len = 0;
  
  while(low <= mid && high <= r) {
    if(low < high) { // 单独处理左半边
      if(q[low].type == 0) {
        update(q[low].y, 1);
      }
      tmp[len++] = q[low++];
    }
    else
    {
      if(q[high].type == 1) {
        ans[q[high].id] +=  q[high].op * query(q[high].y);
      }
      tmp[len++] = q[high++];
    }
  }
  while(low <= mid) tmp[len++] = q[low++];
  // 再处理左半边对右半边的影响
  while(high <= r)
  {
    if(q[high].type == 1) {
      ans[q[high].id] += q[high].op * query(q[high].y);
    }
    tmp[len++] = q[high++];
  }
  // 相当于撤销
  for(int i = 0; i < len; i++) {
    q[i+l] = tmp[i];
    Clear(tmp[i].y);
  }
}
int main(int argc, char const *argv[]) {
  // freopen("in.txt","r",stdin);
  int n,m;
  int id = 0;
  std::cin >> n >> m;
  for(int i = 1; i <= n; i++) {
    int x,y;
    std::cin >> x >> y;
    q[++id].x = x + 1;
    q[id].y = y + 1;
    k = max(k, y + 1);
  }
  k++;
  // （aj，bj）为左下坐标，以（cj，dj）为右上坐标
  int aj,bj,cj,dj;
  for(int i = 1; i <= m; i++) {
    std::cin >> aj >> bj >> cj >> dj;
    aj++,bj++;cj++;dj++;
    // 在坐标系上容斥
    q[++id].x = aj - 1; q[id].y = bj - 1; q[id].op = 1; q[id].type = 1; q[id].id = i;
    q[++id].x = aj - 1; q[id].y = dj    ; q[id].op = -1; q[id].type = 1;q[id].id = i;
    q[++id].x = cj    ; q[id].y = bj - 1; q[id].op = -1; q[id].type = 1;q[id].id = i;
    q[++id].x = cj    ; q[id].y = dj    ; q[id].op = 1; q[id].type = 1;q[id].id = i;
  }
  // std::cout << "id = " << id << '\n';
  cdq(1,id);
  for(int i = 1; i <= m; i++) {
    std::cout << ans[i] << '\n';
  }
  return 0;
}
