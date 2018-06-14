class Solution {
public:
    // 找两个字符串中最长的唯一的子字符串的长度,相同就-1
    int findLUSlength(string a, string b) {
        if(a == b) return -1;
        else return max(a.size(),b.size());
    }
};