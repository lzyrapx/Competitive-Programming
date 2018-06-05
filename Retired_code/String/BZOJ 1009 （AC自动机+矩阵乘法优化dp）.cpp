#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000100;
int mod;

// AC自动机有三个部分，分别是建树，获取失配指针和查询。
// Aho_Corasick_Automaton ：可以简单的理解为将KMP放在Trie树上

// https://www.lydsy.com/JudgeOnline/problem.php?id=1009

int End[maxn];
int ch[maxn][26];
int fail[maxn];
int sz;

struct matrix
{
  int m[26][26];
  void init() {
    memset(m,0,sizeof(m));
  }
};
matrix operator *(matrix a, matrix b)
{
  matrix ans;
  ans.init();
  for(int i = 1; i <= sz + 1; i++) {
    for(int j = 1; j <= sz + 1; j ++) {
      for(int k = 1; k <= sz + 1; k++) {
        ans.m[i][j] += a.m[i][k] * b.m[k][j];
        ans.m[i][j] %= mod;
      }
    }
  }
  return ans;
}
matrix qpower(matrix a, int b)
{
  matrix ans;
  ans.init();
  for(int i = 1; i <= sz + 1; i++) {
    ans.m[i][i] = 1;
  }
  while(b > 0)
  {
    if(b & 1) ans = ans * a;
    b >>= 1;
    a = a * a;
  }
  return ans;
}
void insert(string s)
{
  int now = 0;
  for(int i = 0; i < (int)s.size();i++) {
    int c = s[i] - '0';
    if(!ch[now][c])ch[now][c] = ++sz;
    now = ch[now][c];
  }
  End[now] = 1;
}
void getfail()
{
  queue<int>que;
  for(int i = 0; i <= 9; i++) {
    if(ch[0][i]) {
      que.push(ch[0][i]);
      fail[ch[0][i]] = 0;
    }
  }
  while(!que.empty())
  {
    int u = que.front();
    que.pop();
    for(int i = 0; i <= 9; i++) {
      int v = ch[u][i];
      if(v)
      {
        fail[v] = ch[fail[u]][i];
        // 注意如果一个数字的后缀是不吉利的(即fail指针指向不吉利数字的结尾节点)
        // 那么这个数字一定也是不吉利的
        End[v] |= End[ch[fail[u]][i]];
        que.push(v);
      }
      else ch[u][i] = ch[fail[u]][i];
    }
  }
}
string s;
int n,m;
int dp[maxn][26];
// dp[i][j]表示串长为 i , 匹配到了 AC 自动机的节点 j，并且从来没有出现过完整的不吉利号码的方案数。
int main(int argc, char const *argv[]) {
  // freopen("in.txt","r",stdin);
  std::cin >> n >> m >> mod;
  std::cin >> s;
  insert(s);
  getfail();

  // dp[0][0] = 1;
  // for(int i = 1; i <= n; i++) {
  //   for(int j = 0; j <= sz; j++) {
  //     for(int k = 0; k <= 9; k++) {
  //       int v = ch[j][k];
  //       if(End[v] == 0) {
  //         dp[i][v] += dp[i - 1][j];
  //         dp[i][v] %= mod;
  //       }
  //     }
  //   }
  // }
  // int res = 0;
  // for(int i = 0; i <= sz; i++) {
  //   res += dp[n][i];
  //   res %= mod;
  // }
  // std::cout << "res = " << res << '\n';

  matrix a,tmp;
  a.init();
  tmp.init();
  tmp.m[1][1] = 1;
  for(int i = 0; i <= sz; i++) {
    for(int j = 0; j <= 9; j++) {
      int v = ch[i][j];
      if(End[v] == 0) {
        a.m[i + 1][v + 1] += 1;
      }
    }
  }
  a = tmp * qpower(a,n);

  int ans = 0;
  for(int i = 1; i <= sz + 1; i++) {
    ans += a.m[1][i];
    ans %= mod;
  }
  std::cout << ans << '\n';
  return 0;
}