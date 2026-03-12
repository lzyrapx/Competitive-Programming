#include<stdio.h>
#include<math.h>
#include<iostream>
#define PI acos(-1.0)
#define g  9.87

int main()
{
	double v,m,a;
	double H2=0.5; int H1=3;
	while(~scanf("%lf%lf%lf",&v,&m,&a))
	{
		double Vx=v*cos(a*PI/180); //水平速度 
		double Vy=v*sin(a*PI/180);  //垂直速度 
		double x,t1,t2,t;
		if(Vy*Vy/(2*g)>H2)		//吐得超过天花板。。。。 
		{   
	        double t1=2*(Vy-sqrt(Vy*Vy-2*H2*g))/g; //吐上天花板时：上升和下落 
            double t2=(sqrt(Vy*Vy+2*g*H1)-Vy)/g; // 下落 
            t=t1+t2;  
		}
		else   //吐不到天花板 
        {
            t=2*Vy/g+(sqrt(Vy*Vy+2*g*H1)-Vy)/g;
        }
        x=t*Vx; 
		printf("%.3lf\n",x);
	}
	return 0;
}