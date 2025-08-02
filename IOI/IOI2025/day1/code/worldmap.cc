#include <bits/stdc++.h>

#include "worldmap.h"

using namespace std;

vector<int> vis;
vector<vector<int>> gr;
deque<int> ord;

void dfs(int x) {
  ord.push_back(x);
  vis[x] = 1;
  for (auto y : gr[x])
    if (!vis[y]) {
      dfs(y);
      ord.push_back(x);
    }
}

vector<vector<int>> create_map(int n, int m, vector<int> A, vector<int> B) {
  gr.clear();
  gr.resize(n);
  vis.assign(n, 0);
  for (int i = 0; i < m; ++i) {
    gr[A[i] - 1].push_back(B[i] - 1);
    gr[B[i] - 1].push_back(A[i] - 1);
  }
  dfs(0);
  int sz = 2 * n;
  vector<vector<int>> ret(sz, vector<int>(sz, 0));
  int a = -1, b = -1;
  vector<int> don(n, 0);
  while (ord.size()) {
    if (a <= b) {
      auto cu = ord[0];
      ord.pop_front();
      for (int i = 0; i <= a; ++i) ret[i][a - i] = cu + 1;
      a++;
      if (don[cu]) continue;
      don[cu] = 1;
      int tmp = 0;
      for (auto x : gr[cu])
        if (don[x]) {
          ret[tmp][a - tmp] = x + 1;
          tmp++;
        }
      while (tmp <= a) {
        ret[tmp][a - tmp] = cu + 1;
        tmp++;
      }
      a++;
      for (int i = 0; i <= a; ++i) ret[i][a - i] = cu + 1;
      a++;
    } else {
      auto cu = ord.back();
      ord.pop_back();
      for (int i = 0; i <= b; ++i) ret[sz - b - 1 + i][sz - i - 1] = cu + 1;
      b++;
      if (don[cu]) continue;
      don[cu] = 1;
      int tmp = 0;
      for (auto x : gr[cu])
        if (don[x]) {
          ret[sz - b - 1 + tmp][sz - 1 - tmp] = x + 1;
          tmp++;
        }
      while (tmp <= b) {
        ret[sz - b - 1 + tmp][sz - 1 - tmp] = cu + 1;
        tmp++;
      }
      b++;
      for (int i = 0; i <= b; ++i) ret[sz - b - 1 + i][sz - i - 1] = cu + 1;
      b++;
    }
  }
  for (int i = 0; i < sz; ++i) {
    for (int j = 0; j < sz; ++j) {
      if (!ret[i][j]) {
        if (i && ret[i - 1][j])
          ret[i][j] = ret[i - 1][j];
        else
          ret[i][j] = ret[i][j - 1];
      }
    }
  }
  return ret;
}