#include<algorithm>
#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;

int main()
{
    int t,n,i;
    cin>>t;
    while(t--)
    {
        cin>>n;
        vector<int> v(n);
        for(i=0;i<n;i++) v[i]=i+1;
           int f=0;
           while(v.size()>3)
           {
               f++;
               if(f%2==1)
               {
               	for(i=1;i<v.size();i++)
                  v.erase(v.begin()+i);
			   }
               else
               {
               	 for(i=2;i<v.size();i=i+2)
                 v.erase(v.begin()+i);
			   }
                  
           }
           vector<int>::iterator it=v.begin();
           int first=0;
           for(;it!=v.end();it++)
           {
           	 if(!first)
              {
               cout<<*it;
               first=1;
              }
               else cout<<" "<<*it;
		   }   
        cout<<endl;
    }
	return 0;
}