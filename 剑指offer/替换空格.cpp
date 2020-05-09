class Solution {
public:

void replaceSpace(char *str,int length) {
        int count=0;
        for(int i=0;i<length;i++){
            if(str[i]==' '){
                count++;
            }
        }
        int len=length+2*count;
        int i=length-1;
        int j=len-1;
        while(i >= 0 && j >= 0) //往后填
        {
            if(str[i]!=' '){
                str[j]=str[i];
                --i;
                --j;
            }
            else{
                str[j--]='0';
                str[j--]='2';
                str[j--]='%';
                --i;
            }
        }
    }
};