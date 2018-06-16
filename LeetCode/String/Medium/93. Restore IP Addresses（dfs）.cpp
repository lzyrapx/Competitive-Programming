class Solution {
public:
    // 输出IP地址的所有合法方案
    vector<string> restoreIpAddresses(string s) {
        vector<string>ans;
        dfs(ans,s,0,"",0);
        return ans;
    }
    void dfs(vector<string>&ans,string s, int pos, string tmp, int num)
    {
        if(num > 4) return;
        
        if(pos >= s.size()) {
           if(num == 4) {
                tmp.pop_back();
                ans.push_back(tmp);
           }
            return ;
        }
        // 3 digit
        if(s[pos] != '0'&& pos < s.size() - 2 && stoi(s.substr(pos,3)) < 256) {
            dfs(ans, s, pos + 3, tmp + s.substr(pos, 3) + ".", num + 1);
        }
        // cout << "after 3 digit :" << tmp << endl;
        // 2 digit
        if(s[pos] != '0' && pos < s.size() - 1 && stoi(s.substr(pos,2)) < 256) {
            dfs(ans, s, pos + 2, tmp + s.substr(pos, 2) + ".", num + 1);
        }
        // cout << "after 2 digit :" << tmp << endl;
        // 1 digit
        // 有0.0.0.0的情况, 不能s[pos] != '0'
        if(pos < s.size() && stoi(s.substr(pos,1)) < 256) {
            dfs(ans, s, pos + 1, tmp + s.substr(pos, 1) + ".", num + 1);
        }

        // cout << "after 1 digit :" << tmp << endl;
    }
};
/*
IP地址=网络地址＋子网地址＋主机地址
A类地址范围：1.0.0.1---126.255.255.254
B类地址范围：128.0.0.1---191.255.255.254
C类地址范围：192.0.0.1---223.255.255.254
D类地址范围：224.0.0.1---239.255.255.254(D类一般不用。而是广播ip地址)
E类地址范围：240.0.0.1---255.255.255.254（为将来使用保留）
*/