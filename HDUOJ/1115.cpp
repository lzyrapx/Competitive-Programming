
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int cas , n ;
struct center
{
       double x , y ;
};
double Area( center p0 , center p1 , center p2 )
{
       double area = 0 ;
       area =  p0.x * p1.y + p1.x * p2.y + p2.x * p0.y - p1.x * p0.y - p2.x * p1.y - p0.x * p2.y;
       return area / 2 ;  
}
int main ()
{
    center p0 , p1 , p2 ;
    double sum_x , sum_y , sum_area , area;
    scanf ( "%d" , &cas ) ;
    while ( cas -- )
    {
          sum_x = sum_y = sum_area = 0 ;
          scanf ( "%d" , &n ) ;
          scanf ( "%lf%lf" , &p0.x , &p0.y ) ;
          scanf ( "%lf%lf" , &p1.x , &p1.y ) ;
          
          for ( int i = 2 ; i < n ; ++ i )
          {
              scanf ( "%lf%lf" , &p2.x , &p2.y ) ;
              area = Area(p0,p1,p2) ;
              sum_area += area ;
              sum_x += (p0.x + p1.x + p2.x) * area ;
              sum_y += (p0.y + p1.y + p2.y) * area ;
              p1 = p2 ;
          }
          printf ( "%.2lf %.2lf\n" , sum_x / sum_area / 3 , sum_y / sum_area / 3 ) ;
    }
    return 0 ;
}