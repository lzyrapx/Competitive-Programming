
#include <stdio.h>
#include <string.h>
int a[55],b[55]; //a数组保存最后的结果
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		a[0] = 1;
		int num;
		//第一层循环表示一共有 n个小括号 
		for(int i = 1;i <= 26;i ++)
		{
			scanf("%d",&num);
		
			//第二个循环表示把每个小括号里面的每一项
			//都要与前面一个小括号里面的每一项计算 
			for(int j = 0;j <= 50;j ++)
			   //k表示第j个的指数 
			   //第三个循环是要控制每一项里面 X 增加的比例 
		  		for(int k = 0;k <= num && k*i+j <= 50;k ++)
		  		//合并同类项，将它们的系数加起来
		  		//即指数相同，系数相加 
		     		b[k*i+j] += a[j];
		     
			//刷新一下数据，继续进行下一次计算，
			//就是下一项括号里面的每一项 	
			for(int j = 0;j <= 50;j ++)
			{
				a[j] = b[j];
				b[j] = 0;
			}
		}	
		
		int ans = 0;
		//注意：总价值不能为0，所以不能计算1*x^0 
		//计算了会多 1  
		for(int i = 1;i <= 50;i ++) ans += a[i];
		
		printf("%d\n",ans);
	}
	return 0;
}
