#include <bits/stdc++.h>
using namespace std;
const int maxn = 100100;

// Aho_Corasick_Automaton ：可以简单的理解为将KMP放在Trie树上
// https://www.luogu.org/problemnew/show/P2444
// AC自动机模板

// 题意：是否可以构造一个可行的无限长文本串，使没有任何子串为给出模式串中的一个
int End[maxn];
int ch[maxn][26];
int fail[maxn];
int sz;
void insert(string s)
{
  int now = 0; //字典树的当前指针
  for(int i = 0; i < (int)s.size();i++) {
    int c = s[i] - '0';
    // //Trie树没有这个子节点 : 就构造出来
    if(!ch[now][c]) ch[now][c] = ++sz;
    now = ch[now][c]; //然后向下构造
  }
  End[now]++; //标记单词结尾
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
    for(int i = 0; i <= 1; i++) { //枚举所有子节点
      int v = ch[u][i];
      if(v) { //存在这个子节点
        //子节点的 fail指针指向当前节点的 fail指针所指向的节点的相同子节点
        fail[v] = ch[fail[u]][i];
        
        //因为fail指针指向的是当前串的最长后缀
        //如果fail指向的后缀是病毒，那当前串一定是病毒。
        if(End[fail[ch[u][i]]]) {
          End[ch[u][i]]++;
        }
        que.push(v);
      }
      // 不存在这个子节点
      // 当前节点的这个子节点指向当前节点fail指针的这个子节点
      else ch[u][i] = ch[fail[u]][i];
    }
  }
}
bool ins[maxn]; // 记录每个节点在 当前 dfs 走的路径上有没有被选中
bool vis[maxn]; // 记录每个节点历史上有没有被访问过
bool dfs(int u)
{
  ins[u] = true;
  for(int i = 0; i <= 1; i++) {
    int v = ch[u][i];
    if(ins[v]) return true;
    if(vis[v] == true || End[v] != 0) continue; // 避免危险标记，也就是说如果下一个结点拥有危险标记，就不走那个结点
    vis[v] = true;
    if(dfs(v)) return true;
  }
  ins[u] = false;
  return false;
}
string s;
int main(int argc, char const *argv[]) {
  int n;
  std::cin >> n;
  for(int i = 1; i <= n; i++) {
    std::cin >> s;
    insert(s);
  }
  getfail();
  if(dfs(0)) { // 这个环要求必须经过根节点，且不经过一些限制节点
    std::cout << "TAK" << '\n'; //存在安全代码,找到一个不经过病毒点的环
  }
  else std::cout << "NIE" << '\n'; // 有环
  return 0;
}
