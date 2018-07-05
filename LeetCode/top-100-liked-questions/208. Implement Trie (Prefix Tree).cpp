class TrieNode {
public:
    // Initialize your data structure here.
    bool isWord = false;
    TrieNode* son[26];
        
    TrieNode() 
    {
        memset(son, NULL, sizeof(son));
    }
};
class Trie {
private:
    bool mySearch(string& word, bool isPrefix) 
    {
        TrieNode* cur = root;
        for (int i = 0; i < word.length(); i++) {
            int idx = word[i] - 'a';
            if (!cur->son[idx]) { 
                return false; 
            }
            cur = cur->son[idx];
        }
        return isPrefix || cur->isWord;
    }
private:
    TrieNode* root;
    
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* cur = root;
        for (int i = 0; i < word.length(); i++) 
        {
            int idx = word[i] - 'a';
            if (!cur->son[idx]) 
            { 
                cur->son[idx] = new TrieNode(); 
            }
            cur = cur->son[idx];
        }
        cur->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        return mySearch(word, false);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
         return mySearch(prefix, true);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */