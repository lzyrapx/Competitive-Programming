#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 50010;

int que[maxn << 1];
int ans[maxn];
int numz;
int node[maxn << 1];

struct Query{
  int x,y,z;
  int op,id;
  Query() {}
  Query(int _x, int _y, int _z, int _op, int _id) : x(_x), y(_y), z(_z), op(_op), id(_id) {}
}queries[maxn << 3],queries_x[maxn << 3],queries_y[maxn << 3];

bool cmpx(Query a, Query b)
{
  return a.x < b.x || (a.x == b.x && a.op < b.op);
}
bool cmpy(Query a, Query b)
{
  return a.y < b.y || (a.y == b.y && a.op < b.op);
}

inline int lowbit(int x){ return x&-x; }
void update(int pos, int val)
{
  while(pos <= numz)
  {
    node[pos] += val;
    pos += lowbit(pos);
  }
}
int query(int pos)
{
  int res = 0;
  while(pos > 0) {
    res += node[pos];
    pos -= lowbit(pos);
  }
  return res;
}
// 只剩下二维 y 和  z，直接就是二维的更新查询题目，树状数组解决就好了
void solve3(int l, int r)
{
  if(l >= r) return;
  for(int i = l; i <= r; i++) {
    if(queries_y[i].op == 0) {
      update(queries_y[i].z, 1);
    }
    else if(queries_y[i].op == 1) {
      ans[queries_y[i].id] -= query(queries_y[i].z);
    }
    else if(queries_y[i].op == 2) {
      ans[queries_y[i].id] += query(queries_y[i].z);
    }
  }
  for(int i = l; i <= r; i++) {
    if(queries_y[i].op == 0) {
      update(queries_y[i].z, -1);
    }
  }
}
//把 x 这一维度消除
void solve2(int l, int r)
{
  if(l >= r) return;
  int mid = (l + r) >> 1;
  solve2(l, mid);
  solve2(mid + 1, r);
  int num = 0;
  for(int i = l; i <= mid; i++) {
    if(queries_x[i].op == 0) {
      queries_y[num++] = queries_x[i];
    }
  }
  for(int i = mid + 1; i <= r; i++) {
    if(queries_x[i].op > 0) {
      queries_y[num++] = queries_x[i];
    }
  }
  sort(queries_y,queries_y + num,cmpy);
  solve3(0, num - 1);
}
// 已经默认时间从小到大排序了，可以把时间这一维度消除
void solve1(int l,int r)
{
  if(l >= r) return ;
  int mid = (l + r) >> 1;
  solve1(l, mid);
  solve1(mid + 1, r);
  int num = 0;
  for(int i = l; i <= mid; i++) {
    if(queries[i].op == 0) {
      queries_x[num++] = queries[i];
    }
  }
  for(int i = mid + 1; i <= r; i++) {
    if(queries[i].op > 0) {
      queries_x[num++] = queries[i];
    }
  }
  sort(queries_x, queries_x + num, cmpx);//对 x 从小到大排序
  solve2(0, num - 1);
}
int main(int argc, char const *argv[]) {
  int t;
  std::cin >> t;
  int x1,x2,y1,y2,z1,z2;
  while(t--)
  {
    memset(ans,-1,sizeof(ans));
    numz = 0;
    int n;
    int id = 0;
    std::cin >> n;
    for(int i = 0; i < n; i++) {
      int op;
      std::cin >> op;
      if(op == 1) {
        std::cin >> x1 >> y1 >> z1;
        queries[id++] = Query{x1,y1,z1,0,i};
        que[numz++] = z1;
      }
      else
      {
        ans[i] = 0;
        std::cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        // 分成八个查询, 容斥原理 : 和树状数组查询有关
        queries[id++] = Query{x2, y2, z1 - 1, 1, i};
        queries[id++] = Query{x2, y2, z2, 2, i};

        queries[id++] = Query{x2, y1 - 1, z2, 1, i};
        queries[id++] = Query{x1 - 1, y1 - 1, z2, 2, i};

        queries[id++] = Query{x1 - 1, y2, z2, 1, i};
        queries[id++] = Query{x1 - 1, y2, z1 - 1, 2, i};

        queries[id++] = Query{x1 - 1, y1 - 1, z1 - 1, 1, i};
        queries[id++] = Query{x2, y1 - 1, z1 - 1, 2, i};

        que[numz++] = z1 -1;
        que[numz++] = z2;
      }
    }

    sort(que,que+numz);
    numz = unique(que,que+numz) - que;
    for(int i = 0; i < id; i++) {
      queries[i].z = lower_bound(que,que + numz,queries[i].z) - que + 1;
    }
    solve1(0, id - 1); // cdq
    for(int i = 0; i < n; i++) {
      if(ans[i] != -1) {
        std::cout << ans[i] << '\n';
      }
    }
  }
  return 0;
}
