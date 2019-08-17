#include <bits/stdc++.h>
#include <list>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 123;
const int mod = 1000000007;
char s[maxn];
pair<int, int> arr[maxn];
int num;
int main(int argc, char const *argv[]) {
  int n, k;
  while (cin >> n >> k) {
    scanf("%s", s + 1);
    num = 0;
    int len = strlen(s + 1);
    bool flag = true;
    for (int i = 1; i <= len; i++) {
      if (s[i] == '1') {
        if (s[i - 1] == '1') {
          arr[num - 1].first += 1;
        }
        else {
          arr[num].second = 0;
          arr[num++].first = 1;
        }
      } else
        flag = false;
    }
    if (flag == true) {
      std::cout << n << '\n';
      continue;
    }
    int low = 0, high = 0;
    if (s[1] == '1') {
      low = arr[0].first;
      arr[0].second = 1;
    }
    if (s[len] == '1') {
      high = arr[num - 1].first;
      arr[num - 1].second = len;
    }
    int ans = 0;
    if (k) {
      sort(arr, arr + num);
      if (low) {
        int pos = num - 1;
        int tmp = k;
        int res = low;
        while (tmp > 1 && pos >= 0) {
          if (arr[pos].second == 1) {
            pos--;
            continue;
          }
          res += arr[pos].first;
          pos--;
          tmp -= 2;
        }
        ans = max(ans, res);
      }
      if (num > 0) {
        int pos = num - 2;
        int tmp = k - 1;
        int res = arr[num - 1].first;
        while (tmp > 1 && pos >= 0) {
          res += arr[pos].first;
          pos--;
          tmp -= 2;
        }
        ans = max(ans, res);
      }
      if (high > 0) {
        int pos = num - 1;
        int tmp = k - 1;
        int res = high;
        if (arr[pos].second == len)  {
          pos--;
        }
        if (tmp && pos >= 0) {
          res += arr[pos].first;
          pos--;
          tmp--;
        }
        while (tmp > 1 && pos >= 0) {
          if (arr[pos].second == len) {
            pos--; continue;
          }
          res += arr[pos].first;
          pos--;
          tmp -= 2;
        }
        ans = max(ans, res);
      }
      if (low > 0 && high > 0) {
        int tmp = k - 1;
        int pos = num - 1;
        int res = high + low;
        while (tmp > 1 && pos >= 0) {
          if (arr[pos].second == 1 || arr[pos].second == len) {
            pos--;
            continue;
          }
          res += arr[pos].first;
          pos--;
          tmp -= 2;
        }
        ans = max(ans, res);
      }
    }
    else {
        ans = low;
    }
    std::cout << ans << '\n';
  }
  return 0;
}
