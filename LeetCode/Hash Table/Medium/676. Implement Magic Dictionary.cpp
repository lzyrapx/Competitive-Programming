class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        
    }
    vector<string>tmo;
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for(auto s : dict) {
            tmo.push_back(s);
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) { //查找编辑距离为1的字符串
        for(auto s: tmo) {
            if(s.size() == word.size()) {
                int cnt = 0;
                for(int i = 0;  i < s.size(); i++) {
                    if(s[i] != word[i]) {
                        cnt++;
                    }
                }
                if(cnt == 1) return true;
            }
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */