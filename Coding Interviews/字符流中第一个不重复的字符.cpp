class Solution
{
public:
     //Insert one char from stringstream
    string s;
    char hash[256];
    void Insert(char ch)
    {
        s = s + ch;
        hash[ch]++;
    }
    //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
       int sz = s.size();
       for(int i = 0; i < sz; i++) {
           if(hash[s[i]] == 1) {
               return s[i];
           }
       }
        return '#';
    }

};