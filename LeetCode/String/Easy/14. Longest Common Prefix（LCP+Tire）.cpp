class Solution {
public:
    /*  Trie   */
    /*  动态建立,注意释放内存  */
    struct Trie{  
        Trie *next[26];  
        int cnt;  
        //string str;  
    }*root;  
  
    int len;
    string ans;  
  
    void insert(string s)
    {  
        Trie *p = root,*pnew;  
        for(int i = 0;i < s.size();++ i)
        {  
            int x = s[i] - 'a';  
            if(p->next[x] == NULL)
            {  
                pnew = new Trie;  
                pnew->cnt = 1;  
                for(int j = 0;j < 26;++ j)
                {  
                    pnew->next[j] = NULL;  
                }  
                p->next[x] = pnew;  
            }  
            else p->next[x]->cnt++;  
            p=p->next[x];  
        }  
    }  
  
  
    int find(string s)
    {  
        Trie *p = root;  
        bool f = 0;  
        for(int i = 0;i < s.size();++ i)
        {  
            int x = s[i] - 'a';  
            if(p->next[x] == NULL) return 0;  
            if(p->next[x]->cnt == len){  
                ans = s.substr(0,i + 1);  
                f = 1;  
            }  
            p = p->next[x];  
        }  
        return f;  
    }  
  
    void init()
    {  
        root = new Trie;  
        root->cnt = 0;  
        for(int i = 0;i < 26;++ i){  
            root->next[i] = NULL;  
        }  
    }  
  
    string longestCommonPrefix(vector<string>& strs) {
        len = strs.size();
        if(len == 0) return "";
        init();
        for(int i = 0; i < len ;i++)
        {
            insert(strs[i]);
        }
        if(find(strs[0]) == 0) return ans = "";
        return ans;
    }
};