#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
char in[3]={'A','B','C'};
string getstring(string str)
{
    int l=str.length();
    if(l<=1) return str; //这里需要注意
    string ss="";
    for(int i=0;i<l-1;i++)
    {
        if(str[i]==str[i+1])
        {
            while(i+1<l&&str[i]==str[i+1]) i++;
        }
        else ss+=str[i];
    }
    if(str[l-1]!=str[l-2]) ss+=str[l-1];
    return ss;
}
int main()
{
    
    int t,max;
    string s;
    cin>>t;
    while(t--)
    {
        cin>>s;
        max=0;
        for(int i=0;i<s.length()-1;i++)
        {
            for(int j=0;j<3;j++)  //两重循环枚举。
            {
                string str=s.substr(0,i+1)+in[j]+s.substr(i+1);
                int len=str.length();
                str=getstring(str);
                while(len>str.length())
                {
                    len=str.length();
                    str=getstring(str);
                }
                if(s.length()-len+1>max)  max=s.length()-len+1;
            }
        }
        cout<<max<<endl;
    }
    return 0;
}