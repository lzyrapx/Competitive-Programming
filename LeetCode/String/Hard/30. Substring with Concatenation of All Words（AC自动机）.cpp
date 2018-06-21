class Solution {
public:
        struct Aho_Corasick 
        {     
            int sz;    
            int ch[10000][27];    
            int val[10000];   
            int f[10000];  
            int lens;  
            unordered_map<int, int> flag;  
              
            int idx(char c) {return c - 'a';}  
            Aho_Corasick(string s) {   
                sz = 1;  
                lens = s.length();  
                memset(ch[0], 0, sizeof(ch[0]));  
            };            
            void insert(string str, int v) {    
                int u = 0, n = str.length();    
                for(int i = 0; i < n; i++) {    
                    int c = idx(str[i]);    
                    if(!ch[u][c]) {    
                        memset(ch[sz], 0, sizeof(ch[sz]));    
                        val[sz] = 0;  
                        ch[u][c] = sz++;    
                    }      
                    u = ch[u][c];    
                }    
                val[u] = v;  
            }    
  
            void getFail() { 
                queue<int> q;  
                f[0] = 0;  
                for(int c = 0; c < 26; c++) {  
                    int u = ch[0][c];  
                    if(u) {  
                        f[u] = 0;   
                        q.push(u);  
                    }  
                }  
                while(!q.empty()) {  
                    int r = q.front(); q.pop();  
                    for(int c = 0; c < 26; c++) {  
                        int u = ch[r][c];  
                        if(!u) {  
                            ch[r][c] = ch[f[r]][c];  
                            continue;  
                        }  
                        q.push(u);  
                        int v = f[r];  
                        while(v && !ch[v][c]) v = f[v];  
                        f[u] = ch[v][c];  
                    }  
                }  
            }  
            void find_T(string s, int lenw) {  
                int j = 0;  
                for(int i = 0; i < lens; i++) {  
                    int c = idx(s[i]);  
                    j = ch[j][c];  
                    if(val[j]) flag[i-lenw+1] = val[j];  
                }  
            }   
        };
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if(s.size() == 0 || words.size()== 0) return ans;
        Aho_Corasick ac = Aho_Corasick(s); 

        int cnt = words.size();  
        int lenw = words[0].length();  

        map<string, int> dic;  
        map<int, int> num;  

        int id = 0;  
        for (int i = 0; i < cnt; i++) {    
            if(!dic.count(words[i])) dic[words[i]] = ++id;  
            num[dic[words[i]]]++;  
        }  
        for (int i = 0; i < cnt; i++) {
            ac.insert(words[i], dic[words[i]]);  
        }  
        
        ac.getFail();  
        ac.find_T(s, lenw);   
        
        for (int i = 0; i < lenw; i++) 
        {  
            int left = i;  
            int word_cnt = 0;  
            map<int, int> tmp_cnt;  
            for (int j = i; j < ac.lens; j+=lenw) 
            {  
                if (!ac.flag[j]) 
                {  
                    left = j + lenw;  
                    word_cnt = 0;  
                    tmp_cnt.clear();  
                }  
                else 
                {  
                    int v = ac.flag[j];  
                    tmp_cnt[v]++;  
                    word_cnt++;  
                    if (tmp_cnt[v] > num[v]) 
                    {  
                        do 
                        {  
                            tmp_cnt[ac.flag[left]]--;  
                            left += lenw;  
                            word_cnt--;  
                        } while (ac.flag[left-lenw] != v);  
                    }  
                    if (word_cnt == cnt) {
                         ans.push_back(left);  
                    }  
                }  
            }   
        }  
        return ans;  
    }
};
