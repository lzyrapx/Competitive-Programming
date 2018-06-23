class Solution {
public:
    // 1.对整体，1的个数等于0的个数
    // 2.对任意前缀，1的个数>=0的个数，第一个必须是1
    // 要求我们任意交换两个相邻的(长度任意)子串(可以交换任意次)使得最终得到的序列的字典序最大,并且是特殊二进制串。
    // 要使字典序最大，第一个必须是1，最后一个必须是0
    string makeLargestSpecial(string S) {
        string ans;
        if(S.size() == 0) return ans;
        // 
        vector<string>specials;
        int cnt = 0;
        // 分割成小特殊二进制串
        for(char ch : S)
        {
            if(cnt == 0) specials.push_back("");
            if(ch == '1') cnt++;
            else cnt--;
            specials.back() += ch;
        }
        // 把每个小特殊二进制串搞成字典序最大的
        // 要使字典序最大，第一个必须是1，最后一个必须是0
        for(string &s: specials)
        {
            s = "1" + makeLargestSpecial(s.substr(1,s.size() - 1 - 1)) + "0";
        }
        // 将这些小特殊二进制串按字典序从大到小排序
        sort(specials.begin(),specials.end(),greater<string>());
        
        //合并
        for(string s : specials)
        {
            ans += s;
        }
        return ans;
    }
};