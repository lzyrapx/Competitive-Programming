// luogu-judger-enable-o2
#include <bits/stdc++.h>
using namespace std;
const int maxn = 300100;
// Aho_Corasick_Automaton ：可以简单的理解为将KMP放在Trie树上
// https://www.luogu.org/problemnew/show/P3796
// AC自动机模板
int num[maxn];
int ch[maxn][26];
int fail[maxn];
int ans[maxn];
int sz;
void insert(string s, int index)
{
  int now = 0;
  for(int i = 0; i < (int)s.size();i++) {
    int c = s[i] - 'a';
    if(!ch[now][c]) ch[now][c] = ++sz;
    now = ch[now][c];
  }
  num[now] = index;
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
      //  当前节点的这个子节点指向当前节点fail指针的这个子节点
      else ch[u][i] = ch[fail[u]][i];
    }
  }
}
void query(string s)
{
  int now = 0;
  for(int i =0; i < (int)s.size(); i++) {
    now = ch[now][s[i]-'a'];
    for(int j = now; j ; j = fail[j]) {
      ans[num[j]]++;
    }
  }
}
string s[maxn];
int main(int argc, char const *argv[]) {
  int n;
  while(1)
  {
    std::cin >> n;
    if(n == 0) break;
    memset(num,0,sizeof(num));
    memset(ans,0,sizeof(num));
    memset(ch,0,sizeof(ch));
    memset(fail,0,sizeof(fail));
    sz = 0;
    for(int i = 1; i <= n; i++) {
      std::cin >> s[i];
      insert(s[i],i);
    }
    getfail();
    string k;
    std::cin >> k;
    query(k);
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
      if(ans[i] > cnt) {
        cnt = ans[i];
      }
    }
    std::cout << cnt << '\n';
    for(int i = 1; i <= n; i++) {
      if(ans[i] == cnt) {
        std::cout << s[i] << '\n';
      }
    }
  }
  return 0;
}