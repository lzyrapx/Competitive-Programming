#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>

using namespace std;

const int maxn = 3 * 1e5 + 123;
int m, n;
int black[maxn];
int white[maxn];
int t[maxn], l[maxn], r[maxn], c[maxn];
int seg[maxn];
int main(int argc, char const *argv[]) {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> black[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> white[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> t[i] >> l[i] >> r[i] >> c[i];
    for (int j = l[i]; j <= r[i]; j++) seg[j] = 1;  //在区间
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    if (seg[i] == 0) {
      ans += max(black[i], white[i]);
    }
  }
  for (int i = 1; i <= m; i++) {
    long long maxx = 0, black_seg = 0, white_seg = 0;
    for (int j = l[i]; j <= r[i]; j++) {
      black_seg += black[j];
      white_seg += white[j];
      maxx += max(black[j], white[j]);
    }
    if (t[i] == 1) {
      ans += max(maxx, c[i] + black_seg);
    } else {
      ans += max(maxx, c[i] + white_seg);
    }
  }
  cout << ans << endl;
  return 0;
}
