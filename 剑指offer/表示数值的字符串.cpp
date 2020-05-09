class Solution {
public:
    bool isNumeric(char* string)
    {
        int len = strlen(string);
         if(len == 0) return true;
        int i = 0;
        int nume = 0;
        int num = 0;
        int dot = 0;
       if(string[0] == '+' || string[0] == '-') {
           i++;
       }
       while(i < len)
       {
           if(string[i] >= '0' && string[i] <= '9') {
               i++;
               num = 1;
           }
           else if(string[i] == '.') {
               if(nume > 0) return false;
               dot++;
               i++;
           }
           else if(string[i] == 'e' || string[i] == 'E') {
               if(nume > 0 || num == 0) return false;
               nume++;
               i++;
               if(string[i]=='-' || string[i]=='+') {
                   i++;
               }
               if(string[i] =='\0') return false;
           }
           else return false;
       }
        if(dot > 1 || nume > 1)return false;
        return true;
    }

};