class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string>ans;
        if(source.size() == 0) return ans;
        bool block = false;
        string tmp;
        for(string s : source)
        {
            for(int i = 0; i < s.size();)
            {
                if(block == false)
                {
                    if(i == s.size() - 1) {
                        tmp += s[i];
                        i++;
                    }
                    else
                    {
                        string now = s.substr(i,2);
                        if(now == "/*")
                        {
                            block = true;
                            i += 2;
                        }
                        else if(now == "//") break;
                        else 
                        {
                            tmp += s[i];
                            i++;
                        }
                    }
                }
                else // block
                {
                    if(i == s.size() - 1) i++;
                    else
                    {
                        string now = s.substr(i,2);
                        if(now == "*/") {
                            block = false;
                            i += 2;
                        }
                        else i++;
                    }
                }
            }
            // 注意 ： block == false 才 push
            if(tmp.size() != 0 && block == false) {
                ans.push_back(tmp);
                tmp.clear();
            }
        }
        return ans;
    }
};