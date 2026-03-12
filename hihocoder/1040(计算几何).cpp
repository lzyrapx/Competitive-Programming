#include <cstdio>
#include <cstring> 
#include <algorithm>
#include <set>
using namespace std;
struct point
{
	int x, y;
	bool operator < (const point& p2) const      //用于排序 
    {  
        //先判断横坐标  
        if(x<p2.x||(x==p2.x&&y<p2.y)) return true;  
        return false;  
    }  
    bool operator == (const point& p2) const       //用于判等 
    {  
        return (x==p2.x&&y==p2.y);  
    }
};
struct line
{
	point p1, p2;
};
int judgePoint(line *l)
{
	set<point> s;
	for(int i=0; i<4; i++)
	{
		s.insert(l[i].p1);
		s.insert(l[i].p2);
	}
	return (s.size() == 4);
}
int judgeRect(line *l)
{
	for(int i=1; i<4; ++i)  
    {  
        //判断是不是垂直  
        if((l[0].p1.y-l[0].p2.y)*(l[i].p1.y-l[i].p2.y)==-(l[0].p1.x-l[0].p2.x)*(l[i].p1.x-l[i].p2.x))  
            continue;  
        //判断是不是平行  
        if((l[0].p1.y-l[0].p2.y)*(l[i].p1.x-l[i].p2.x)==(l[0].p1.x-l[0].p2.x)*(l[i].p1.y-l[i].p2.y))  
            continue;  
        return false;  
    }  
    return true;  
}
int main()
{
	line l[4];
	int T;
	scanf("%d", &T);
	while(T--)
	{
		for(int i=0; i<4; i++)
			scanf("%d %d %d %d", &l[i].p1.x, &l[i].p1.y, &l[i].p2.x, &l[i].p2.y);
		int flag = 0;
		if(judgePoint(l) && judgeRect(l)) flag = 1;
		if(flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}