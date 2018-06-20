class Solution {
public:
    // 最长非共同子序列
    // All the given strings' lengths will not exceed 10.
    // 先我们给字符串按长度来排序，将长度大的放到前面，如果找到了非共同子序列，
    // 那么直接返回其长度即可，因为当前找到的肯定是最长的.
    int findLUSlength(vector<string>& strs) {
        int sz = strs.size();
        set<string>se;
        // 从长到短排序
        sort(strs.begin(),strs.end(),[](string a, string b){
            if(a.size() == b.size()) return a > b;
            else return a.size() > b.size();
        });
        for(int i = 0; i <= sz - 1; i++) 
        {
            // cout << strs[i] << endl;
            if((i == sz - 1 || (strs[i] != strs[i + 1]))) 
            {
                bool f = true;
                for(string s: se) 
                {   
                    // cout << s << endl;
                    int j = 0;
                    for(char ch : s) 
                    {
                        if(strs[i][j] == ch) j++;
                        // 如果当前的字符串strs[i]是集合中某个字符串的子序列
                        // 直接break
                        if(j == strs[i].size()) break;
                    }
                    if(j == strs[i].size()) // 共同了
                    {
                        f = false; break;
                    }
                }
                if(f == true) return strs[i].size();
            }
            se.insert(strs[i]);
        }
        return -1;
    }
};