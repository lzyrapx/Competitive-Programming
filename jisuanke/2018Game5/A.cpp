#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 1e6 + 11;
int n;
int dp[maxn],dp2[maxn];
void init()
{
  for(int i = 1; i <= 1e6; i++) {
    dp[i] = dp2[i] = 1e9;
  }
  for(int i = 1; i <= 1e6; i++) {
    for(int j = 1; i * j <= 1e6; j++) {
      dp[i * j] = min(dp[i * j], (i + 2) * (j + 2));
    }
  }
  for(int i = 1; i <= 1e6; i++) {
    for(int j = 1; i * j<=1e6;j++) {
      dp2[i * j] = min(dp2[i * j], dp[i] * (j + 1));
    }
  }
}
int main(){
  init();
  int t;
  std::cin >> t;
  while(t--) {
    std::cin >> n;
    int mx = (n + 1) * 3 * 3 - n;
    int mi = dp2[n] - n;
    std::cout << mi << " " << mx << '\n';
  }
}
