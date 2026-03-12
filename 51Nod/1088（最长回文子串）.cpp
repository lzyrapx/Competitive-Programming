#include <bits/stdc++.h>
using namespace std;
char ch[1234];
int main()
{  
    int m=0;
	int len;
    scanf("%s", ch);
    len=strlen(ch);
    for(int i=0; i<len; i++)//i表表示中间子串的中间位置
	{ 
	//子串长度为奇数的情况, j表示对称位置的长度
        for(int j=0; i-j>=0&&j+i<len; j++)
        {
            if(ch[i-j]!=ch[i+j]){
                break;
            }
			else
			{
                m=max(m, 2*j+1);
            }
        }
    //子串长度为偶数的情况, j表示左边中间位置到开始位置的长度
        for(int j=0; i-j>=0&&i+j+1<len; j++)
		{ 
            if(ch[i-j]!=ch[i+j+1])
			{
                break;
            }
			else
			{
                m=max(m, 2*j+2);
            }
        }
    }
    cout<<m<<endl;
    return 0;
}