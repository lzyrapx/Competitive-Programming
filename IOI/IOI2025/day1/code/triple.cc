#include <bits/stdc++.h>

#include "triples.h"

using namespace std;

typedef long long ll;

constexpr int inf = 1e9 + 100;

long long count_triples(std::vector<int> H) {
  int N = H.size();
  vector<int> X(N), Y(N), cnt(N * 3);
  vector<vector<int>> buf(N * 3), Q(N * 3);

  ll ans = 0;

  for (int i = 0; i < N; i++) {
    X[i] = i - H[i] + N, Y[i] = i + H[i] + N;
    buf[X[i]].push_back(Y[i]);
  }

  for (int i = 0; i < N; i++) {  // O(Nsqrt(N))
    if (buf[X[i]].size() > buf[Y[i]].size())
      Q[X[i]].push_back(Y[i]);
    else
      Q[Y[i]].push_back(X[i]);
  }

  for (int i = 0; i < N * 3; i++)
    if (!Q[i].empty()) {
      for (auto &j : Q[i]) {
        for (auto &y : buf[j]) cnt[y]++;
      }

      for (auto &y : buf[i]) ans += cnt[y];

      for (auto &j : Q[i]) {
        for (auto &y : buf[j]) cnt[y]--;
      }
    }

  // O(N) bruteforce

  auto valid = [&](int i, int j, int k) {
    if (!(0 <= i && i < j && j < k && k < N)) return 0;
    int a[3] = {j - i, k - j, k - i};
    int b[3] = {H[i], H[j], H[k]};

    sort(a, a + 3);
    sort(b, b + 3);

    for (int t = 0; t < 3; t++)
      if (a[t] != b[t]) return 0;

    return 1;
  };

  for (int i = 0; i < N; i++) {  // case 1: H[i] is the longest
    int k = i + H[i];
    if (k < 0 || k >= N) continue;

    int j = i + H[k];  // case 1-1
    ans += valid(i, j, k);

    if (j != k - H[k]) {  // case 1-2
      j = k - H[k];
      ans += valid(i, j, k);
    }
  }

  for (int k = 0; k < N; k++) {  // case 2: H[k] is the longest
    int i = k - H[k];
    if (i < 0 || i >= N) continue;

    int j = i + H[i];  // case 2-1
    ans += valid(i, j, k);

    if (j != k - H[i]) {  // case 2-2
      j = k - H[i];
      ans += valid(i, j, k);
    }
  }

  for (int i = 0; i < N; i++) {  // case 3: H[j] is the longest
    int j = i + H[i];
    if (j < 0 || j >= N) continue;

    int k = i + H[j];

    if (j - i != k - j) {
      ans += valid(i, j, k);
    }
  }

  return ans;
}

std::vector<int> construct_range(int M, int K) {
  int N = M;
  vector<int> X = {-1}, Y = {1}, used(N * 2), C = {0}, H(N), V(N * 2, -inf);
  for (int i = 2; i < N * 2; i += 2) V[i] = 1;

  while (true) {
    auto it = max_element(V.begin(), V.end());
    int mx = *it, opt = it - V.begin();

    if (mx == 0) break;

    for (auto &x : C) {
      if (x + opt < N * 2 && !used[x + opt]) {
        used[x + opt] = 1;
        if (x < opt) {
          X.push_back(x);
          Y.push_back(opt);
        }

        else {
          X.push_back(opt);
          Y.push_back(x);
        }

        for (auto &y : C) {
          int z = x + opt - y;
          if (0 <= z && z < N * 2) V[z]--;
        }
      }
    }

    for (int i = 0; opt + i < N * 2; i += 2)
      if (!used[opt + i]) V[i]++;

    C.push_back(opt);
    V[opt] = -inf;
  }

  assert((int)X.size() == N);
  for (int i = 0; i < N; i++) H[(X[i] + Y[i]) / 2] = (Y[i] - X[i]) / 2;

  ll cnt = count_triples(H);
  while (cnt < K) {
    for (int i = 0; i < N; i++) {
      for (int j = 1; j <= N - 1; j++) {
        int tmp = H[i];
        H[i] = j;

        ll cnt2 = count_triples(H);
        if (cnt2 > cnt)
          cnt = cnt2;
        else
          H[i] = tmp;
      }
    }
  }

  return H;
}