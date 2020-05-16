/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-05-16 17:22:28
 */ 
class WordFilter {
 public:
  /*  Trie   */
  /*  静态化,注意内存开辟大小    */
  int wide = 26;        //每个节点的最大子节点数
  int ch[1 << 18][28];  //内存开辟尽量最大
  int val[1 << 18];
  int sz;
  map<int, int> mp;
  void init() {
    sz = 1;
    memset(ch[0], 0, sizeof(ch[0]));
  }
  inline int idx(char c)  //字母映射
  {
    if (c == '#') return 27;
    return c - 'a';
  }
  // v 从 1 开始标号,
  // 调用了insert(word[i],i)语句，如果给模板标号0的话相当于舍弃了这个模板串(v==0代表非单词结点)
  void insert(string s, int v, int weight)  //建立Trie树, v 从 1 开始标号
  {
    int i, len = s.size(), c, u = 0;
    for (i = 0; i < len; i++) {
      c = idx(s[i]);
      if (!ch[u][c]) {
        memset(ch[sz], 0, sizeof(ch[sz]));
        val[sz] = 0;
        ch[u][c] = sz++;
      }
      u = ch[u][c];
      mp[u] = weight;
    }
    val[u] = v;
  }
  int find(string s)  //查找
  {
    int i, len = s.size(), c, u = 0;
    for (i = 0; i < len; i++) {
      c = idx(s[i]);
      if (!ch[u][c]) return 0;
      u = ch[u][c];
    }
    for (i = 0; i < wide; i++) {
      if (ch[u][c]) return u;  // s串是模板串中某个串的prefix
    }
    return u;  //存在
  }
  WordFilter(vector<string>& words) {
    init();
    int cnt = 1;
    // apple: #apple, e#apple, le#apple, ple#apple, pple#apple, apple#apple,
    for (int i = 0; i < words.size(); i++) {
      for (int j = 0; j <= words[i].size(); j++) {
        insert(words[i].substr(j) + "#" + words[i], cnt, i);
        cnt += 1;
      }
    }
  }
  int f(string prefix, string suffix) {
    int idx = find(suffix + "#" + prefix);
    if (idx == 0) {
      return -1;
    }
    if (idx > 0) {
      return mp[idx];
    }
    return 0;
  }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */