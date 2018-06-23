class Solution {
public:
    bool isValid(string code) {
        stack<string> st;
        for (int i = 0; i < code.size(); i++) 
        {
            if (i > 0 && st.empty()) return false;
            if (code.substr(i, 9) == "<![CDATA[") 
            {
                int j = i + 9;
                i = code.find("]]>", j);
                if (i == -1) return false;
                i += 2;
            } 
            else if(code.substr(i, 2) == "</") 
            {
                int j = i + 2;
                i = code.find(">", j);
                if (i == -1) return false;
                string tag = code.substr(j, i - j);
                if (st.empty() || st.top() != tag) return false;
                st.pop();
            } 
            else if(code.substr(i, 1) == "<") 
            {
                int j = i + 1;
                i = code.find(">", j);
                if (i == -1 || i == j || i - j > 9) return false;
                for (int k = j; k < i; k++) 
                {
                    if (code[k] < 'A' || code[k] > 'Z') return false;
                }
                string tag = code.substr(j, i - j);
                st.push(tag);
            }
        }
        return st.empty();
    }
};
/*
给定字符串判断是否为有效标签
1.整个字符串应为一个闭合标签
2.闭合标签的格式为<TAG_NAME>TAG_CONTENT</TAG_NAME>，其中<TAG_NAME>为标签头，</TAG_NAME>为标签尾，TAG_CONTENT为标签内容。
3.TAG_NAME只应当包含大写字母，长度1-9
4.TAG_CONTENT可包含其他有效的闭合标签，cdata以及其他有效字符，不可以包含失配的'<'、标签头和标签尾
5.标签头如果没有同名标签尾相互匹配，即为失配，反之亦然。然而，同时还需要考虑嵌套标签的匹配问题。
6.'<'如果没有'>'相互匹配，即视为失配。当遇到'<'或者'</'时，到下一个'>'之前的子串视为TAG_NAME（不一定有效）
7.cdata格式为：<![CDATA[CDATA_CONTENT]]>。CDATA_CONTENT为<![CDATA[与第一个]]>之间的部分。
8.CDATA_CONTENT可以包含任意字符。cdata的目的是防止校验器解析CDATA_CONTENT，因此即使其中包含的字符可以解析为标签，也还是将其视为普通字符。

*/