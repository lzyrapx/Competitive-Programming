#include <cstdio>
#include <cstdlib>

double D;
int H,M;
double S, Total;
int signal;
double minimum;
double maximum;

void get_next()
{
	double HM,HS,MS; // HM是时针和分针的夹角, HS是时针和秒针的夹角, MS是分针和秒针的夹角 

	double HL,ML,SL; // HL是时针的位置, ML是分针的位置, SL是秒针的位置 
	
	double t1,t2,t3; // 临时值 
	SL = 6*S; // 秒针的位置是6度乘以当前的秒数 
	ML = 6*(M+S/60); // 分针的位置是6度乘以当前的分数 + 当前的秒数除以10 
	HL = 30*(H+M/60.0+S/3600); // 时针的位置是30度乘以当前的小时数 + 分钟数除以2 + 秒数除以120 
	HM = ML - HL; // 以分针在前, 算出分针和时针的夹角 
	HS = SL - HL; // 以秒针在前, 算出秒针和时针的夹角 
	MS = SL - ML; // 以秒针在前, 算出秒针和分针的夹角 
	
	while(HM+1e-6>=D) HM -= 360; // 如果时针和分针的夹角 >= D, 那么减360 
	
	while(HM+1e-6<D-360) HM += 360; // 如果时针和分针的夹角 < D-360, 那么加360 
	
	while(HS+1e-6>=D) HS -= 360; // 下面的操作是一样的, 目的是把每个夹角控制在 D-360 到 D之间

	while(HS+1e-6<D-360) HS += 360; // 那样的话, 只要夹角小于-D, 他们就是Happy的
	
	while(MS+1e-6>=D) MS -= 360; // 如果在-D和D之间, 就不happy   
	
	while(MS+1e-6<D-360) MS += 360;
	
	if(HM>=-D||HS+1e-10>=-D||MS+1e-10>=-D) // 如果有任何一个夹角处于 -D到D之间 
	{
		signal = 0; // 标记为Unhappy 
		t1 = (D - HM)/(1.0/10 - 1.0/120); // 时针和分针需要经过t1才变得happy 
		t2 = (D - HS)/(6-1.0/120); // 时针和秒针要经过t2才变得happy 
		t3 = (D - MS)/(6-1.0/10); // 分针和秒针要经过t3才变得happy 
		minimum = 0; // 下面是算t1, t2, t3的最大值 
		if(HM>=-D) minimum = minimum > t1? minimum : t1;
		if(HS+1e-6>=-D) minimum = minimum > t2? minimum : t2;
		if(MS+1e-6>=-D) minimum = minimum > t3? minimum : t3;
		S += minimum; // 移动秒针到可能的happy处 
		while(S>=60) // 恢复正常的表示方式 
		{
			S-=60;
			M++;
		}
		while(M>=60) // 恢复正常的表示方式 
		{
			M-=60;
			H++;
		}
		return;
	}
	else
	{
		signal = 1; // 标记为happy 
		t1 = (-D - HM)/(1.0/10 - 1.0/120); // 时针和分针经过t1会变得unhappy 
		t2 = (-D - HS)/(6-1.0/120); // 时针和秒针经过t2会变得unhappy 
		t3 = (-D - MS)/(6-1.0/10); // 秒针和分针经过t3会变得unhappy 
		maximum = 100000;  // 下面是算t1, t2, t3的最小值 
		maximum = maximum < t1? maximum : t1;
		maximum = maximum < t2? maximum : t2;
		maximum = maximum < t3? maximum : t3;
		S += maximum; // 移动到unhappy处 
		while(S>=60) // 恢复正常的表示方式 
		{
			S-=60;
			M++;
		}
		while(M>=60) // 恢复正常的表示方式 
		{
			M-=60;
			H++;
		}
		return;
	}
}

int main()
{
	while(scanf("%lf",&D)&&D!=-1) // 读取数字 
	{
		if(D==0) // 特殊处理 
		{
			printf("100.000\n");
			continue;
		}
		if(D>=120) // 特殊处理 
		{
			printf("0.000\n");
			continue;
		}
		H = M = 0; // 初始化时间 
		S = 0; // 初始化时间 
		Total = 0; // Happytime 
		while(1)
		{
			get_next(); // 得到下一个临界时间 
			if(H>=12) break; // 如果超过12小时, 就不管了, 跳出 
			if(signal) Total += maximum; // 如果从现在到下一个临界时间是Happy的, 就加上Maximum的Happy时间 
		}
		printf("%.3lf\n",Total/432); // Total/432 % 就是总共happy的百分比 
	}
}
