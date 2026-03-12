#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<iomanip>
const int MAX=150;
const double INF=0xfffff;
double DP[MAX];		//DP[i]表示到第i个加电站的最小耗费时间
int s[MAX];		//s[i]表示到第i个加电站距离起点的距离
using namespace std;
double Min(double x,double y)//判断大小
{
    return x>y?y:x;
}
int main()
{
    double L;
    int n,i,j;
    double c,t;
    double vr,vt_1,vt_2;
    double len,sum,Time;
    while(cin>>L)//输入跑道长度
    {
        cin>>n>>c>>t;	
        cin>>vr>>vt_1>>vt_2;	
        for(i=1;i<=n;i++) cin>>s[i];
        s[n+1]=L;		//把第n+1个加电站设为终点，长度为L
        s[0]=0;			//把第0个加电站设为起点，长度为0
        DP[0]=0;		//起点到起点最小耗费时间为0
        for(i=1;i<=n+1;i++)
        {
            DP[i]=INF;			//因为到第i个加电站最小耗费时间未知所以赋值无穷大
            for(j=0;j<i;j++)
            {
                len=s[i]-s[j];			//从第j个加电站到第i个加电站的距离
                if(len>c)		//如果该距离大于电动车能行驶的最大距离
               		Time=c/vt_1 + (len-c)/vt_2;		//把电动车行驶的时间加上乌龟用脚踏的时间
                else
                	Time=len/vt_1;	//这段距离除于电动车的速度所得的时间
                	Time+=DP[j];	//再加上到第j个加电站的最优时间
                if(j>0)  	//这里判断j>0是因为如果j==0的话,即表明从起点出发，因为起点已经充满电了所以不需要加上电动车的充电时间
                {
                    Time+=t;	//如果j>0加上电动车的充电时间
                }
                DP[i]=Min(DP[i],Time);	//每次挑出到第i个加电站的最优时间
            }
        }
        if(DP[n+1]<(L/vr)) //判断 
        cout<<"What a pity rabbit!"<<endl;
        else
        cout<<"Good job,rabbit!"<<endl;
    }
    return 0;
}