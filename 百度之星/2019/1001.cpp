#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
typedef long long ll;

using namespace std;

const int maxn = 1e6 + 123;
int f[maxn], g[maxn];
int main(int argc, char const *argv[]) {
  int t;
  int n, m;
  std::cin >> t;
  while(t--) {
    std::cin >> n;
    m = n;
    for(int i = 1; i <= n; i++) {
      std::cin >> f[i];
    }
    for(int i = 1; i <= n; i++) {
      std::cin >> g[i];
    }
    while(f[n] == 0) n -= 1;
    while(g[m] == 0) m -= 1;
    if(n > m) {
      std::cout << "1/0" << '\n';
      continue;
    }
    else if(n < m) {
      std::cout << "0/1" << '\n';
      continue;
    }
    int gcd = __gcd(f[n], g[m]);
    f[n] /= gcd;
    g[m] /= gcd;
    std::cout << f[n] << "/" << g[m] << '\n';
  }
  return 0;
}
