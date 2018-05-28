#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 505000;
const int mod = (1 << 30);

// https://www.lydsy.com/JudgeOnline/problem.php?id=1176

/*
输入1:你需要把(x,y)(第x行第y列)的格子权值增加 a
输入2:你需要求出以左下角为(x1,y1),右上角为(x2,y2)的矩阵内所有格子的权值和,并输出
输入3:表示输入结束
*/

// 删除操作不用时间倒流 版本

struct Query{
  int x,y,val,pos,id,op;
  Query(){}
  Query(int pos_,int x_,int y_,int op_,int id_,int val_) {
   pos = pos_,  x = x_, y = y_, op = op_, id = id_; val = val_;
  }
  bool operator <(const Query &a) const {
    return x < a.x || (x == a.x && y < a.y) || (x == a.x && y == a.y && op < a.op);
  }
}q[maxn * 4],tmp[maxn * 4];

int k = 2000010;
int w;
int s[maxn * 4];
ll ans[maxn * 4];
inline int lowbit(int x)
{
  return x&(-x);
}
void update(int pos,int val)
{
  while(pos <= w + 1) {
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

void cdq(int l, int r)
{
  if(l >= r) return;
  int mid = (l + r) >> 1;

  int low = l, high = mid + 1;
  for(int i = l; i <= r; i++) {
    if(q[i].id <= mid && q[i].op == 0) {
      update(q[i].y,q[i].val);
    }
    if(q[i].id > mid && q[i].op == 1) {
      ans[q[i].pos] += q[i].val * query(q[i].y);
    }
  }
  //再将树状数组清空
  for(int i = l; i <= r; i++) {
    if(q[i].id <= mid && q[i].op == 0) {
      update(q[i].y,-q[i].val);
    }
  }
  for(int i = l; i <= r; i++) {
    if(q[i].id <= mid) {
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
int S;
int main(int argc, char const *argv[]) {
  // freopen("in.txt","r",stdin);
  std::cin >> S >> w;
  int idx = 0;
  int tot = 0;
  while(true) {
    int op;
    std::cin >> op;
    if(op == 1) { // 1 x y a
      int x,y,a;
      std::cin >> x >> y >> a;
      q[++idx].x = x; q[idx].y = y;
      q[idx].val = a; q[idx].id = idx;
    }
    else if(op == 2) { //2 x1 y1 x2 y2
      int x1, y1 ,x2 ,y2;
      std::cin>> x1 >> y1 >> x2 >> y2;
      tot++;
      q[++idx].pos = tot; q[idx].x = x1 - 1; q[idx].y = y1 - 1;
      q[idx].val = 1; q[idx].op = 1; q[idx].id = idx;

      q[++idx].pos = tot; q[idx].x = x2; q[idx].y = y2;
      q[idx].val = 1; q[idx].op = 1; q[idx].id = idx;

      q[++idx].pos = tot; q[idx].x = x1 - 1; q[idx].y = y2;
      q[idx].val = -1; q[idx].op = 1; q[idx].id = idx;

      q[++idx].pos = tot; q[idx].x = x2; q[idx].y = y1 - 1;
      q[idx].val = -1; q[idx].op = 1; q[idx].id = idx;
    }
    else break;
  }
  sort(q + 1, q + idx + 1);
  cdq(1,idx);
  for(int i = 1; i <= tot; i++) {
    std::cout << ans[i] << '\n';
  }
  return 0;
}
