#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000100;
const int mod = 10007;

// AC自动机有三个部分，分别是建树，获取失配指针和查询。
// Aho_Corasick_Automaton ：可以简单的理解为将KMP放在Trie树上

// https://www.lydsy.com/JudgeOnline/problem.php?id=3172



int End[maxn];
int ch[maxn][26];
int fail[maxn];
int sz;
int pos[maxn], ans[maxn], q[maxn];
int cnt;
void insert(string s, int &pos)
{
  int now = 0; //字典树的当前指针
  for(int i = 0; i < (int)s.size();i++) {
    int c = s[i] - 'a';
    // Trie树没有这个子节点 : 就构造出来
    if(!ch[now][c]) ch[now][c] = ++sz;
    now = ch[now][c]; //然后向下构造

    ans[now]++; //经过该节点的数目
  }
  End[now] = 1;; //标记单词结尾
  pos = now; //记录每一个字符串的最终位置
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

    // 记录bfs序
    q[++cnt] = u;
    
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
int n;
void solve()
{
  // 逆bfs序递推，将当前枚举到的点的fail指针指向的点的权值累加一下
  for(int i = cnt; i >= 1; --i) {
  	 // std::cout << "q =" << q[i] << " " << "fail = " << fail[q[i]] << '\n';
    // std::cout << "ansf =" << ans[fail[q[i]]] << " " << "ansq = " << ans[q[i]] << '\n';
    ans[fail[q[i]]] += ans[q[i]];
  }
  for(int i = 1; i <= n; i++) {
    std::cout << ans[pos[i]] << '\n';
  }
}
string s;
int main(int argc, char const *argv[]) {

  std::cin >> n;
  for(int i = 1; i <= n; i++) {
    std::cin >> s;
    insert(s,pos[i]);
  }
  getfail();
  solve();
  return 0;
}
