#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000100;

// Aho_Corasick_Automaton ：可以简单的理解为将KMP放在Trie树上
// https://www.luogu.org/problemnew/show/P2292

// 输出这段文章在字典D可以被理解的最长前缀的位置


int End[maxn];
int ch[maxn][26];
int fail[maxn];
int sz;
void insert(string s)
{
  int now = 0; //字典树的当前指针
  for(int i = 0; i < (int)s.size();i++) {
    int c = s[i] - 'a';
    // //Trie树没有这个子节点 : 就构造出来
    if(!ch[now][c]) ch[now][c] = ++sz;
    now = ch[now][c]; //然后向下构造
  }
  // 以 now 结尾单词的长度
  End[now] = (int)s.size(); //标记单词结尾
}
void getfail() //构造fail指针
{
  queue<int>que;
  for(int i = 0; i < 26; i ++) {
    if(ch[0][i]) {
      que.push(ch[0][i]);
      fail[ch[0][i]] = 0;  //指向根节点
    }
  }
  while(!que.empty()) { // BFS求fail指针
    int u = que.front();
    que.pop();
    for(int i = 0; i < 26; i++) { //枚举所有子节点
      int v = ch[u][i];
      if(v) { //存在这个子节点
        //子节点的 fail指针指向当前节点的 fail指针所指向的节点的相同子节点
        fail[v] = ch[fail[u]][i];

        que.push(v);
      }
      // 不存在这个子节点
      // 当前节点的这个子节点指向当前节点fail指针的这个子节点
      else ch[u][i] = ch[fail[u]][i];
    }
  }
}
int ans;
int dp[maxn];// dp[i]表示文章的字符到位置 i 是否合法
void solve(string s){
  ans = 0;
  int now = 0;
  for(int i = 0; i < (int)s.size(); i++)
  {
    now = ch[now][s[i] - 'a'];
    for(int j = now; j ; j = fail[j])
    {
      if(End[j] != 0) {
        dp[i + 1] |= dp[i + 1 - End[j]];
        if(dp[i + 1]) {
          ans = max(ans, i + 1);
        }
      }
    }
  }
}
string s;
int main(int argc, char const *argv[]) {
  int n;
  int m;
  ios::sync_with_stdio(0);
  cin.tie(0);
  std::cin >> n >> m;
  for(int i = 1; i <= n; i++) {
    std::cin >> s;
    insert(s);
  }
  getfail();
  for(int i = 1; i <= m; i++) {
    std::cin >> s;
    memset(dp,0,sizeof(dp));
    dp[0] = 1;
    solve(s);
    std::cout << ans << '\n';
  }
  return 0;
}
