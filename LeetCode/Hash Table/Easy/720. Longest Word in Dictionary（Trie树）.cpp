class Solution {
public:
    struct Trie
    {
        int cnt; // 每个节点存的次数
        struct Trie* next[26]={NULL};// 每个节点存储两个节点指针
        Trie():cnt(0){}
        
    };
    Trie* build(vector<string>words) {
        Trie* root = new Trie();
        for(auto word: words)
        {
            Trie* cur = root;
            for(auto s: word)
            {
                if(cur -> next[s -'a'] == NULL) {
                    cur -> next[s - 'a'] = new Trie();
                }
                cur = cur -> next[s - 'a'];
            }
            cur -> cnt = max(cur -> cnt, 1);
        }
        return root;
    }
    string find(Trie* root, string ans)
    {
        if(root == NULL) return "";
        string tmp = ans;
        for(int i = 0; i < 26; i++) 
        {
            if(root -> next[i] && root -> next[i] -> cnt > 0) 
            {
                char c = (i + 'a');
                string cur = c + find(root -> next[i], tmp);
                if(ans.size() < cur.size()) 
                {
                    ans = cur;
                }
            }
        }
        return ans;
    }
    string longestWord(vector<string>& words) {
        Trie* root = build(words);
        return find(root,"");
    }
};