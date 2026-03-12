#include <bits/stdc++.h>
#include <list>
using namespace std;
typedef long long ll;
const int maxn = 156789;

list<int> lis[maxn];

void read(int &x) {
  char ch = getchar();
  x = 0;
  for (; ch < '0' || ch > '9'; ch = getchar())
    ;
  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
}
int main(int argc, char const *argv[]) {
  int n, q;
//  freopen("in.txt","r",stdin);
  while (cin >> n >> q) {
    for (int i = 0; i <= n; i++) {
      lis[i].clear();
    }
    int s;
    for(int i =1 ; i <= q; i++) {
      // std::cin >> s;
      read(s);
      if (s == 1) {
        int u, w, val;
        std::cin >> u >> w >> val;
        if (w == 0) {
          lis[u].push_front(val);
        } else {
          lis[u].push_back(val);
        }
      } else if (s == 2) {
        int u, w;
        // cin >> u >> w;
        read(u);
        read(w);
        if (lis[u].empty()) {
          printf("-1\n");
          continue;
        }
        if (w == 0) {
          printf("%d\n", lis[u].front());
          lis[u].pop_front();
        } else {
          printf("%d\n", lis[u].back());
          lis[u].pop_back();
        }
      } else {
        int u, v, w;
        // std::cin >> u >> v >> w;
        read(u);
        read(v);
        read(w);
        if (w == 0) {
          lis[u].splice(lis[u].end(), lis[v]);
        } else {
          lis[v].reverse();
          lis[u].splice(lis[u].end(), lis[v]);
        }
      }
    }
  }
  return 0;
}
Close
