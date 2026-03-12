// luogu-judger-enable-o2
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 505000;
const int mod = (1 << 30);

// https://www.luogu.org/problemnew/show/P3374
// 强行 cdq分治
// 开O2才能 AC
/*
已知一个数列，你需要进行下面两种操作：
1.将第x个数加上 y
2.输出区间[x,y]内每个数的和
*/
int n,m;

struct Query{
  int x,pos,val,id;
  Query(){}
  Query(int _x,int _pos,int _val,int _id) {
    x = _x, pos = _pos, val = _val,id = _id;
  }
  bool operator <(const Query & a) const {
    return x < a.x || (x == a.x && pos < a.pos);
  }
}q[maxn * 4],tmp[maxn * 4];

int tot;
int ans[maxn * 4];
void cdq(int l, int r)
{
  if(l >= r) return;
  int mid = (l + r) >> 1;
  // 处理所有操作的前一半的修改对后一半的查询的贡献
  int sum = 0;
  for(int i = l; i <= r; i++) {
    if(q[i].pos == 0 && q[i].id <= mid) {
      sum += q[i].val;
    }
    else if(q[i].pos > 0 && q[i].id > mid) { //第二个查询操作
      ans[q[i].pos] += q[i].val * sum;
    }
  }
  int low = l, high = mid + 1;
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
  // 分治前一半、后一半
  cdq(l, mid);
  cdq(mid + 1, r);
}
int main(int argc, char const *argv[]) {
  // freopen("in.txt","r",stdin);
  scanf("%d%d",&n,&m);
  int idx = 0;
  for(int i = 1; i <= n; i++) {
    int a;
    scanf("%d",&a);
    idx++;
    q[idx] = Query{i,0,a,idx};
  }
  for(int i = 1; i <= m; i++) {
    int op,x,y;
    scanf("%d%d%d",&op,&x,&y);
    if(op == 1) {
      idx++;
      q[idx] = Query{x,0,y,idx};
    }
    else {
      idx++;
      q[idx] = Query{x - 1, ++tot, -1, idx};
      idx++;
      q[idx] = Query{y, tot, 1, idx};
    }
  }
  sort(q+1,q+idx+1); //按照 x 和操作的位置排序
  cdq(1,idx);
  for(int i = 1; i <= tot; i++) {
    std::cout << ans[i] << '\n';
  }
  return 0;
}
