#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
#include<iomanip>
#include<algorithm>
typedef long long LL;
using namespace std;

int main()
{
	int n,m,i,j,count,t;
	double s1,s2;
	int stu[55][6];
	double ave1[6],ave2[6];
	while(~scanf("%d%d",&n,&m))
	{
		int flag=0;
		count=t=0;
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				scanf("%d",&stu[i][j]);
		//求个人的平均成绩
        for(i=0;i<n;i++)   
		{
			s1=0;
			if(flag==1)
			 printf(" ");
			for(j=0;j<m;j++)
			{
				s1+=stu[i][j];
			}
			ave1[i]=s1/m;
			printf("%.2f",ave1[i]);
			flag=1;
		}
		printf("\n");
		flag=0;
		//求每科的平均成绩
		for(j=0;j<m;j++)  
		{
			s2=0;
			if(flag==1)
			 printf(" ");
			 for(i=0;i<n;i++)
			   s2+=stu[i][j];
			ave2[j]=s2/n;
			printf("%.2f",ave2[j]);
			flag=1;
		}
		printf("\n");
		//求人数
		for(i=0;i<n;i++)  
		{
			t=0;
			for(j=0;j<m;j++)
			 if(stu[i][j]>=ave2[j])
			   t++;
			if(t==m)
			 count++;
		}
		printf("%d\n\n",count);
}

	return 0;
}