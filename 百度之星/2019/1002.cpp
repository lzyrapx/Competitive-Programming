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
int l[maxn], r[maxn];
int a[maxn], pos[maxn];
int num;
int n;
void update(int x) {
  for(int i = 1; i <= num; i++) {
    // std::cout << "ax = " << a[x] << '\n';
    a[x] = min(a[x], a[i] + (abs(pos[i] - pos[x]) + 1) / 2);
  }
}

int main(int argc, char const *argv[]) {
  int t;
  // freopen("in.txt","r", stdin);
  // std::cin >> t;
  scanf("%d", &t);
  while(t--) {
    // std::cin >> n;
    scanf("%d", &n);
    map<int,int>mp;
    // std::cout << "n = " << n << '\n';
    for(int i = 1; i <= n ; i++) {
      // std::cin >> l[i] >> r[i];
      scanf("%d%d",&l[i], &r[i]);
      mp[l[i]] = mp[r[i]] = 0;
      if(l[i] < r[i]) {
        mp[l[i] + 1] = 0;
        mp[r[i] - 1] = 0;
      }
    }
    num = 0;
    for(auto &m : mp) {
      num += 1;
      m.second =  num;
      pos[num] = m.first;
    }
    for(int i = 1; i <= num; i++) {
      a[i] = 0;
    }
    for(int i = 1; i <= n; i++){
      update(mp[l[i]]);
      update(mp[r[i]]);
      if(l[i] < r[i]) {
        update(mp[l[i] + 1]);
        update(mp[r[i] - 1]);
      }
      for(int j = 1; j <= num; j++) {
        if(l[i] > pos[j] || r[i] < pos[j]) {
          a[j] = 1e9;
        }
      }
    }
    int res = 1e9;
    // std::cout << "num = " << num << '\n';
    for(int i = 1; i <= num; i++) {
      // std::cout << "a = " << a[i] << '\n';
      res = min(res, a[i]);
    }
    // std::cout << res << '\n';
    printf("%d\n",res);
  }

  return 0;
}
