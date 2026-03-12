#include<stdio.h>
#include<math.h>
#include<iostream>
int r, x, y ;
double dist(double x1, double y1, double x2, double y2)
{
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)) ;
}
int main ()
{
    int cas = 1 ;
    while (~scanf ("%d%d%d", &r, &x, &y))
    {
    	 if(r==0&&x==0&&y==0)break;
    	 double sx = x, sy = y, ex, ey, t ;
   		 int flag = 0 ;
    		while (1)
   		  {
     	 	 scanf ("%lf%lf", &ex, &ey) ;
      	 	 if (ex < 0 && ey < 0) break ;
      	  	 if (flag) continue ;
      	 	if (dist(sx, sy, ex, ey) <= r+1.0)
       	 	{
        	    printf ("Firefly %d caught at (%.0lf,%.0lf)\n", cas++, ex, ey) ;
        	    flag = 1 ;
       	 	}
       	 	//即使不到下一个萤火虫，但还是要瞬移。按比例求出瞬移后的x，y坐标即可 
       		 t = r*1.0 / dist(sx, sy, ex, ey) ; 
           	 sx = sx + (ex-sx)*t;
       		 sy = sy + (ey-sy)*t;
    	}	
    	if (flag==0) printf ("Firefly %d not caught\n", cas++) ;
	} 
    return 0 ;
}