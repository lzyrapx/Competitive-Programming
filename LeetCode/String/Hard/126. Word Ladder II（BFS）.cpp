class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>>ans;
        
        set<string> dict(wordList.begin(), wordList.end());
        
        if(dict.count(endWord) == 0) return ans;
        
        vector<string>vis;
        queue< vector<string> >q;
        
        q.push({beginWord});
        
        while(!q.empty())
        {
            int sz = q.size();
            for(int i = 0; i < sz; i++) 
            {
                vector<string>cur = q.front(); q.pop();
                string s = cur.back(); // 注意取最后一个，因为push进去的是path，取path的最后一个
                for(auto &c : s) // 修改s中任意一个字符，要引用
                {
                    char last = c;
                    for(c = 'a'; c <= 'z'; c++) // 修改c
                    {
                        if(dict.count(s) == 0) continue;
                        vector<string> path = cur;
                        path.push_back(s);
                        vis.push_back(s);
                        if(s == endWord) ans.push_back(path);
                        else q.push(path);
                    }
                    c = last; // 相当于回溯
                }
            }
           // cout << vis.size() << endl;
            for(string &word : vis) { // 剪枝，把已经出现的单词忽略
            //    cout << word << endl;
                dict.erase(word);
            }
            vis.clear();
        }
        
        return ans;
    }
};