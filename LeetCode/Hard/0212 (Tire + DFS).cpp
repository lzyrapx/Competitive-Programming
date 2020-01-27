/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-01-26 15:01:34
 */
class Solution {
public:
    /*  Trie   */

    /*  静态化,注意内存开辟大小    */

    int wide=26;  //每个节点的最大子节点数
    int ch[1<<18][26];    //内存开辟尽量最大
    int val[1<<18];
    int sz;
    unordered_set<string>se;
    void init()
    {
        sz=1;
        memset(ch[0],0,sizeof(ch[0]));
    }
    inline int idx(char c) //字母映射
    {
        return c-'a';
    }
    // v 从 1 开始标号, 调用了insert(word[i],i)语句，如果给模板标号0的话相当于舍弃了这个模板串(v==0代表非单词结点)
    void insert(string s,int v) //建立Trie树, v 从 1 开始标号
    {     
        int i,len=s.size(),c,u=0;
        for(i = 0;i < len;i++)
        {
            c=idx(s[i]);
            if(!ch[u][c])
            {
                memset(ch[sz],0,sizeof(ch[sz]));
                val[sz]=0;
                ch[u][c]=sz++;
            }
            u=ch[u][c];
        }
        val[u]=v;
    }
    int find(string s)  //查找
    { 
        int i,len=s.size(),c,u=0;
        for(i = 0;i < len;i++){
            c=idx(s[i]);
            if(!ch[u][c]) return 0;
            u=ch[u][c];
        }
        for(i=0;i<wide;i++) {
            if(ch[u][c]) return 1;   //s串是模板串中某个串的prefix
        }
        return 2;  //存在
    }
    int dir[4][2] = {{0, 1},{0, -1},{1, 0}, {-1, 0}};
    void dfs(int i, int j, vector<vector<char>>& board, vector<string>& words, vector<vector<bool>>& vis, string& cur, unordered_set<string>& ans) {
        if(se.find(cur) != se.end()) {
            // cout << cur << endl;
            ans.insert(cur);
        }
        vis[i][j] = true;
        for(int x = 0; x < 4; x++) {
            int dx = i + dir[x][0];
            int dy = j + dir[x][1];
            if(dx >= 0 && dx < board.size() && dy >= 0 && dy < board[0].size() && vis[dx][dy] == false) {
                cur += {board[dx][dy]};
                if(find(cur)) {
                    dfs(dx, dy, board, words, vis, cur, ans);
                    vis[dx][dy] = false;
                }
                cur.pop_back();
            }
        }
        vis[i][j] = false;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        init();
        for(int i = 0; i < words.size(); i++) {
            insert(words[i], i + 1);
            se.insert(words[i]);
        }
        vector<vector<bool>> vis(board.size() + 1, vector<bool>(board[0].size() + 1, false));
        unordered_set<string>ans;
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                string cur = {board[i][j]};
                // if the first char isn't in the trie
                if(find(cur) == false) {
                    continue;
                }
                if(vis[i][j] == false) {
                    // cout << "start = " << cur << endl;
                    dfs(i, j, board, words, vis, cur, ans);
                }
            }
        }
        return {ans.begin(), ans.end()};
    }
};