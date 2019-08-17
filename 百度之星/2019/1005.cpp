#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <map>
typedef long long ll;

using namespace std;

const int maxn = 1e6 + 123;

int t;
int main(int argc, char const *argv[]) {
  /* code */
  // freopen("in.txt","r", stdin);
  std::cin >> t;
  long long n = 0;
  while(t--) {
    std::cin >> n;
    if( n % 6 == 0 || n % 6 == 2) {
      std::cout << n / 2 << '\n';
    }
    else if(n % 6 == 4) {
      std::cout << n - 1 << '\n';
    }
    else if(n % 6 == 3 || n % 6 == 5) {
      std::cout << n / 6 << '\n';
    }
    else {
      std::cout << n / 3 * 2 + 1 << '\n';
    }
  }
  return 0;
}
