class Solution {
public:
	// Return the index of the first occurrence of needle in haystack, 
	//or -1 if needle is not part of haystack.
    int strStr(string haystack, string needle) {
        
        if(haystack.size() == 0 &&  needle.size() == 0) return 0;
        if(haystack.size() == 0) return -1;
        if(haystack.size() < needle.size()) return -1;
        if(needle.size() == 0) return 0;
              
        vector<int>fail(needle.size()+1, -1);
        
        getfail(needle,fail);
        
        int i = 0, j = 0;
        
        while( i < haystack.size())
        {
            while(j != -1 && haystack[i] != needle[j])
            {
               j = fail[j];
            }
            i++;
            j++;
            if(j == needle.size()) return i - j;
        }
        return -1;
    }
    void getfail(string p, vector<int>&fail)
    {
        int len = p.size();
        int i = 0, j = -1;
        fail[0] = -1;
        while(i < len)
        {
            while(j != -1 && p[i] != p[j]) {
               j = fail[j];
            }
            i++;
            j++;
            fail[i] = j;
        }
    }
};