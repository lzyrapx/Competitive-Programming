#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,k=0;
    char x,y,t;

    while(cin>>n>>x>>y)
    {
        if(k!=0)
            cout<<endl;
        k++;
        if(n==1)
        {
            cout<<x<<endl;
            continue;
        }
        if(((n+1)/2)%2!=0)
            t=x,x=y,y=t;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(i==1&&j==1||i==1&&j==n||i==n&&j==1||i==n&&j==n) //四角 
                {
                    cout<<' '; 
                    continue;
                }
                if(i==1||j==1||i==n||j==n)
                    cout<<y;
                else if(i==2||j==2||i==n-1||j==n-1)
                    cout<<x;
                else if(i==3||j==3||i==n-2||j==n-2)
                    cout<<y;
                else if(i==4||j==4||i==n-3||j==n-3)
                    cout<<x;
                else if(i==5||j==5||i==n-4||j==n-4)
                    cout<<y;
                else if(i==6||j==6||i==n-5||j==n-5)
                    cout<<x;
                else if(i==7||j==7||i==n-6||j==n-6)
                    cout<<y;
                else if(i==8||j==8||i==n-7||j==n-7)
                    cout<<x;
                else if(i==9||j==9||i==n-8||j==n-8)
                    cout<<y;
                else if(i==10||j==10||i==n-9||j==n-9)
                    cout<<x;
                else if(i==11||j==11||i==n-10||j==n-10)
                    cout<<y;
                else if(i==12||j==12||i==n-11||j==n-11)
                    cout<<x;
                else if(i==13||j==13||i==n-12||j==n-12)
                    cout<<y;
                else if(i==14||j==14||i==n-13||j==n-13)
                    cout<<x;
                else if(i==15||j==15||i==n-14||j==n-14)
                    cout<<y;
                else if(i==16||j==16||i==n-15||j==n-15)
                    cout<<x;
                else if(i==17||j==17||i==n-16||j==n-16)
                    cout<<y;
                else if(i==18||j==18||i==n-17||j==n-17)
                    cout<<x;
                else if(i==19||j==19||i==n-18||j==n-18)
                    cout<<y;
                else if(i==20||j==20||i==n-19||j==n-19)
                    cout<<x;
                else if(i==21||j==21||i==n-20||j==n-20)
                    cout<<y;
                else if(i==22||j==22||i==n-21||j==n-21)
                    cout<<x;
                else if(i==23||j==23||i==n-22||j==n-22)
                    cout<<y;
                else if(i==24||j==24||i==n-23||j==n-23)
                    cout<<x;
                else if(i==25||j==25||i==n-24||j==n-24)
                    cout<<y;
                else if(i==26||j==26||i==n-25||j==n-25)
                    cout<<x;
                else if(i==27||j==27||i==n-26||j==n-26)
                    cout<<y;
                else if(i==28||j==28||i==n-27||j==n-27)
                    cout<<x;
                else if(i==29||j==29||i==n-28||j==n-28)
                    cout<<y;
                else if(i==30||j==30||i==n-29||j==n-29)
                    cout<<x;
                else if(i==31||j==31||i==n-30||j==n-30)
                    cout<<y;
                else if(i==32||j==32||i==n-31||j==n-31)
                    cout<<x;
                else if(i==33||j==33||i==n-32||j==n-32)
                    cout<<y;
                else if(i==34||j==34||i==n-33||j==n-33)
                    cout<<x;
                else if(i==35||j==35||i==n-34||j==n-34)
                    cout<<y;
                else if(i==36||j==36||i==n-35||j==n-35)
                    cout<<x;
                else if(i==37||j==37||i==n-36||j==n-36)
                    cout<<y;
                else if(i==38||j==38||i==n-37||j==n-37)
                    cout<<x;
                else if(i==39||j==39||i==n-38||j==n-38)
                    cout<<y;
                else if(i==40||j==40||i==n-39||j==n-39)
                    cout<<x;
            }
            cout<<endl;
        }
    }
    return 0;
}