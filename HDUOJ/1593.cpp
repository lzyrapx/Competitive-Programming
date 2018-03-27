/*
题意：两个敌人A和B，A在半径为R的湖面中心、B在湖边，A在湖中划船的速率是V1，A和B在湖岸的速率是V2，给定R、V1、V2，判断A到达岸边是否能逃脱B。
思路：一开始认为A直接朝B的反方向跑，w了，后来才明白首先A要在湖中找到角速度和B相同的同心圆，在同心圆内A的角速度大于B的角速度，同心圆上A、B的角速度相同、然后A直接划往湖边就OK了~ 公式：v=w*r。
*/
#include<iostream>
const double ip=3.1415926;
using namespace std;
int main()
{
	double R,r,v1,v2,sum;
	double time_0,time_e;
	while(cin>>r>>v1>>v2)
	{
		R=(v1*r)/v2;   //同心圆： V1/R(小)=V2/r 所以R(小)=(v1*r)/v2 （因为线速度V=W（角速度）*R（半径）） 
		time_0=(r-R)/v1;  //A
		time_e=(ip*r)/v2;  //敌人 
		if(time_0<time_e)
		puts("Yes");
		else
		puts("No");
	}
	return 0; 
}