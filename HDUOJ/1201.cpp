#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
#include<algorithm>
typedef long long LL;
using namespace std;

int main()
{
	int T,x;
	int y,m,d;
	cin>>T;
	while(T--){
		int sum=0;   //sum为经历的为闰年的次数 
		scanf("%d-%d-%d",&y,&m,&d);
		if(m==2&&d==29){
			printf("-1\n");
			continue;
		}
		if((y%4==0&&y%100!=0||y%400==0)&&m<3) //出生那年 
			sum++;;
			
		x=y+18;
		if((x%4==0&&x%100!=0||x%400==0)&&m>=3)  //十八岁那年 
            sum++;
        for(int i=y+1;i<y+18;i++)
            	if(i%4==0&&i%100!=0||i%400==0)
                 sum++;
        
        printf("%d\n",365*18+sum);

	}
	return 0;
}


