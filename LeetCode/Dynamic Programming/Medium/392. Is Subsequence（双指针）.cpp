class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int lens = s.size();
        int lent = t.size();
        if(lens == 0 && lent > 0) return 1;
        if(lens > 0 && lent == 0) return 0;
        
       //维持两个字符串指针，分别指向s和t，如果当前字符相同，则指针都向后移动，
        //否则只移动t的指针，直到s中出现的字符都在t中出现过了，可以判定s是t的子序列
        int ids = 0 , idt = 0;
        while(ids < lens && idt < lent)
        {
            if(s[ids] == t[idt])
            {
                ids++;
            }
            idt++;
        }
        if(ids == lens)
        {
            return 1;
        }
        else return 0;

    }
};