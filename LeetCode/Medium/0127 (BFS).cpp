/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-06-06 12:31:42
 */ 
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>dict(wordList.begin(), wordList.end());
        queue<pair<string,int>>que;
        que.push({beginWord, 1});
        
        string tmp;
        int step;
        while(!que.empty()) {
            if(que.front().first == endWord) {
                return que.front().second;
            }
            tmp = que.front().first;
            step = que.front().second;
            que.pop();
            
            for(int i = 0; i < tmp.size(); i++) {
                char ch = tmp[i];
                for(char c = 'a'; c <= 'z'; c++) {
                    if(ch == c) continue;
                    tmp[i] = c;
                    if(dict.find(tmp) != dict.end()) {
                        que.push({tmp, step + 1});
                        dict.erase(tmp);
                    }
                    tmp[i] = ch;
                }
            }
        }
        return 0;
    }
};