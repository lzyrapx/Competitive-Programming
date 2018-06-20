class Solution {
public:
    // (0123)
    bool check(string s)
    {
        if(s.size()==1)return true;
        //0.00 is invail
        if(s[0] == '0' && s.back() == '0') return false;
        return true;
        
    }
    // 注意：逗号后面有空格
    vector<string> ambiguousCoordinates(string S) {
        vector<string>ans;
        string res;
        S = S.substr(1,S.size() -1 -1);
        for(int i = 1; i < S.size(); i++) 
        {
            string ls = S.substr(0,i); // 左子串
            if(check(ls)==false) continue;
            string rs = S.substr(i,S.size()); // 右子串
            if(check(rs)==false) continue;
            
            for(int k = 0; k < ls.size(); k++) // 处理左子串
            {
                if(ls[0]=='0') // 前缀0, 即0.xxx或 0
                {
                    if(k > 0) break;
                    if(ls.size() > 1)
                    {
                        res = "(" + ls.substr(0,1) + '.' + ls.substr(1) + ", ";
                    }
                    else if(ls.size() <= 1)
                    {
                        res= "(" + ls + ", ";
                    }
                }
                else //没有前缀0
                {
                    if(k > 0 && ls.back() != '0') // 不能有后缀0
                    {
                        res = "(" + ls.substr(0, k) + "." + ls.substr(k) + ", "; 
                    }
                    else if(k == 0) res = "(" + ls + ", ";
                    else break;
                }
                
                for(int j = 0; j < rs.size(); j++)
                {
                    if(rs[0]=='0') // 前缀0，即0.xxx或 0
                    {
                        if(j > 0) break;
                        if(rs.size() <= 1)
                        {
                            ans.push_back(res + rs + ")");
                        }
                        else
                        {
                            ans.push_back(res + rs.substr(0,1) + "." + rs.substr(1) + ")");
                        }
                    }
                    else  //没有前缀0
                    {
                        if(j > 0 && rs.back() != '0') // 不能有后缀0
                        {
                            ans.push_back(res + rs.substr(0,j) + "." + rs.substr(j) + ")");
                        }
                        else if(j == 0) ans.push_back(res + rs + ")");
                        else break;
                    }
                }
            }
        }
        return ans;
    }
};