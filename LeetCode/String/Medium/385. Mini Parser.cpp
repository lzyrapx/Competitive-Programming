/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        int pos  = 1; //跳过第一个'['符号
        if(s.find_first_of('[',0)  == string::npos) return NestedInteger(stoi(s));
        return solve(pos,s);
    }
    NestedInteger solve(int &pos, string &s)
    {
        NestedInteger ans;
        string tmp = "";
        for(; pos < s.size(); pos++) 
        {
            char ch = s[pos];
            if(ch == '[') {
                pos++;
                NestedInteger t = solve(pos,s);
                ans.add(t);
            }
            else if(ch == ']') {
                if(!tmp.empty()) {
                    ans.add(stoi(tmp));
                }
                tmp = "";
                return ans;
            }
            else if(ch == '-') {
                tmp = tmp + ch;
            }
            // 如果是数字类的字符，则保存在tmp中
            else if(isdigit(ch)) {
                tmp = tmp + ch;
            }
            else if(ch == ',') { //将tmp从字符转化为数字
                if(!tmp.empty()) {
                    ans.add(stoi(tmp));
                }
                tmp = ""; 
            }
        }
        
        if(!tmp.empty()) { // 如果tmp不为空，说明还有数字未加入
            ans.add(stoi(tmp));
        }
        return ans;
    }
};