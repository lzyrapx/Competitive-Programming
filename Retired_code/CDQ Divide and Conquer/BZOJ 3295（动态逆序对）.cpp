#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 505000;
const int mod = (1 << 30);

// https://www.lydsy.com/JudgeOnline/problem.php?id=3295

/*
给1到n的一个排列，按照某种顺序依次删
除m个元素，你的任务是在每次删除一个元素之前统计整个序列的逆序对数.
输出包含m行，依次为删除每个元素之前，逆序对的个数。
*/
// 删除操作不用时间倒流 版本

int n,m;

struct Query{
  int pos,x,y,op,id;
  Query(){}
  Query(int pos_,int x_,int y_,int op_,int id_) {
   pos = pos_,  x = x_, y = y_, op = op_, id = id_;
  }
  bool operator <(const Query &a) const {
    return x < a.x || (x == a.x && y < a.y);
  }
}q[maxn * 4],tmp[maxn * 4];

int k = 100100;

int s[maxn * 4];
int id[maxn];
ll ans[maxn * 4];
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
void cdq(int l,int r)
{
  if(l >= r) return;
  int mid = (l + r) >> 1;

  // 左边
  for(int i = l; i <= r; i++) {
    if(q[i].pos <= mid) {
      update(q[i].y,q[i].op); // pos, val
    }
    else {
      // 加上或减去它形成的逆序对数
      // q[i].op = 1 就是加操作， -1 就是减操作
      ans[q[i].id] += q[i].op * (query(n) - query(q[i].y));
    }
  }
  for(int i = l; i <= r; i++) {
    if(q[i].pos <= mid) { //并在树状数组中删除
      update(q[i].y, -q[i].op);
    }
  }
  // 右边
  for(int i = r; i >= l; --i) { //注意这里必须倒序
    if(q[i].pos <= mid) {
      update(q[i].y, q[i].op);
    }
    else {
      ans[q[i].id] += q[i].op * query(q[i].y - 1);
    }
  }
  for(int i = l; i <= r; i++) {
    if(q[i].pos <= mid) { //并在树状数组中删除
      update(q[i].y, -q[i].op);
    }
  }

  int low = l, high = mid + 1;
  for(int i = l; i <= r; i++) {
    if(q[i].pos <= mid) {
      tmp[low++] = q[i];
    }
    else {
      tmp[high++] = q[i];
    }
  }
  for(int i = l; i <= r; i++) {
    q[i] = tmp[i];
  }
  cdq(l,mid);
  cdq(mid+1,r);
}
int main(int argc, char const *argv[]) {
  // freopen("in.txt","r",stdin);
  scanf("%d%d",&n,&m);
  int idx = 0;
  int tot = 0;
  for(int i = 1;i <= n; i++) {
    int val;
    std::cin >> val;
    id[val] = i;
    q[++idx] = Query{++tot,id[val],val,1,0}; //pos,x,y,op,id;
  }
  for(int i = 1; i <= m; i++) {
    int val; // 每次删除的一个元素
    std::cin >> val;
    q[++idx] = Query(++tot,id[val],val,-1,i); //pos,x,y,op,id;
  }
  sort(q + 1, q + idx + 1);
  cdq(1,idx);
  for(int i = 1; i <= m; i++) {
    ans[i] += ans[i-1];
    std::cout << ans[i-1] << '\n';
  }
  return 0;
}
