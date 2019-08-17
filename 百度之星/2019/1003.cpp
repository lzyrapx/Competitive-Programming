#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <cstdlib>
// #include<bits/stdc++.h>
typedef long long ll;

using namespace std;

const int maxn = 500 + 10;
vector<pair<long double,int> > ve[maxn * maxn];
int t;
int n, m;
int k;
int x1[maxn], y11[maxn], x2[maxn], y2[maxn];
int Left[maxn][maxn],Right[maxn][maxn],up[maxn][maxn],down[maxn][maxn];
long double tx[maxn], ty[maxn];
long double ans[maxn * maxn];

int dir(int a, int b) {
  return a * m + b;
}
int main(int argc, char const *argv[]) {
  /* code */
  // std::ios::sync_with_stdio(false)
  // freopen("in.txt","r", stdin);
  // std::cin >> t;
  scanf("%d",&t);
  while(t--){
    n = m = 0;
    scanf("%d",&k);
    map<int,int>pointx, pointy;
    for(int i = 1; i <= k; i++) {
      scanf("%d%d%d%d", &x1[i], &y11[i], &x2[i], &y2[i]);
      // std::cin >>  x1[i] >> y11[i] >> x2[i] >> y2[i];

    }
    // std::cin >>  x1[0] >> y11[0] >> x2[0] >> y2[0];
    scanf("%d%d%d%d", &x1[0], &y11[0], &x2[0], &y2[0]);
    for(int i = 0; i <= k; i++) {
      pointx[x1[i]] = 0;
      pointx[x2[i]] = 0;
      pointy[y11[i]] = 0;
      pointy[y2[i]] = 0;
    }
    for(auto &x: pointx) {
      tx[n] = x.first;
      x.second = n;
      n += 1;
    }
    for(auto &y: pointy) {
      ty[m] = y.first;
      y.second = m;
      m += 1;
    }
    // init
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        Left[i][j] = Right[i][j] = 0;
        up[i][j] = down[i][j] = 0;
      }
    }
    for(int i = 0; i < n * m; i++) {
      ve[i].clear();
    }

    for(int i = 1; i <= k; i++) {
      int k1 = pointx[x1[i]], k2 = pointx[x2[i]];
      int k3 = pointy[y11[i]], k4 = pointy[y2[i]];
      for(int j = k1; j <= k2; j++) {
        for(int kk = k3; kk <= k4; kk++) {
          if(kk > k3) {
            Left[j][kk] += 1;
          }
          if(kk < k4) {
            Right[j][kk] += 1;
          }
          if(j > k1) {
            up[j][kk] += 1;
          }
          if(j < k2) {
            down[j][kk] += 1;
          }
        }
      }
    }
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        if(i > 0) {
          ve[dir(i, j)].push_back({(tx[i] - tx[i - 1]) / (up[i][j] + 1), dir(i - 1, j)});
        }
        if(i < n - 1) {
          ve[dir(i, j)].push_back({(tx[i + 1] - tx[i]) / (down[i][j] + 1), dir(i + 1, j)});
        }
        if(j > 0) {
          ve[dir(i, j)].push_back({(ty[j] - ty[j - 1])/ (Left[i][j] + 1), dir(i, j - 1)});
        }
        if(j < m - 1) {
          ve[dir(i, j)].push_back({(ty[j + 1] - ty[j]) / (Right[i][j] + 1), dir(i, j + 1)});
        }
      }
    }
    set< pair<long double, int>> se;
    for(int i = 0; i < n * m; i++) {
      if(i == dir(pointx[x1[0]], pointy[y11[0]])) {
        ans[i] = 0;
      }
      else {
        ans[i] = 1e20;
      }
      se.insert({ans[i], i});
    }
    while(!se.empty()) {
      int id = se.begin() -> second;
      se.erase(se.begin());
      for(auto &y: ve[id]) {
        if(ans[id] + y.first < ans[y.second]) {
          se.erase({ans[y.second], y.second});
          ans[y.second] = ans[id] + y.first;
          se.insert({ans[y.second], y.second});
        }
      }
    }
    printf("%.5lf\n", (double)ans[dir(pointx[x2[0]],pointy[y2[0]])]);
  }
  return 0;
}
