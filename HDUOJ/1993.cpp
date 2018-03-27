#include <iostream>
#include <vector>
 using namespace std;
/*
枚举出以每一个面为中心时，他的四个方向的情况
然后再将答案中给出的一种可能，旋转在同可能的状态比较
*/
 class face
 {
public:
     char C;
     int dir;
     void rotate(int k)
     {
         dir = (dir + k) % 4;
     }
 };

 class state
 {
 public:
     face link[4];
     face mid;
 public:
     void rotate()
     {
         mid.rotate(1);
         face temp = link[3];

         for (int i = 3; i > 0; i--)
             link[i] = link[i-1];
         link[0] = temp;

         for (int i = 0; i < 4; i++)
             link[i].rotate(1);
     }
     bool Compare(state a)
     {
         if (mid.C != a.mid.C || mid.dir != a.mid.dir) return false;

         for (int i = 0; i < 4; i++)
         {
             if (a.link[i].C == '*' || (a.link[i].C == link[i].C && a.link[i].dir == link[i].dir)) continue;
             return false;
         }
         return true;
     }
 };

 face cube[6];

 state P[6];

 bool Find(state ans)
 {
     for (int i = 0; i < 6; i++)
     {
         for (int j = 0; j < 4; j++)
         {
             ans.rotate();
             if (P[i].Compare(ans)) return true;
         }
     }

     return false;
 }

 int main()
 {
     int T;
     scanf("%d", &T);
     getchar();
     for (int ctr = 1; ctr <= T; ctr++)
     {
         vector<int> ret;
             ret.clear();
             int tot = 0;
         for (int i = 0; i < 6; i++)
         {
             char ch;
             int d;
             scanf("%c%d", &ch, &d);
             d--;
             cube[i].C = ch;
             cube[i].dir = d;
         }
         getchar();

         P[0].mid = cube[0];
         P[0].link[0] = cube[4],P[0].link[0].rotate(2);
         P[0].link[1] = cube[3],P[0].link[1].rotate(3);
         P[0].link[2] = cube[2];
         P[0].link[3] = cube[1],P[0].link[3].rotate(1);

         P[1].mid = cube[1];
         P[1].link[0] = cube[0],P[1].link[0].rotate(3);
         P[1].link[1] = cube[2];
         P[1].link[2] = cube[5],P[1].link[2].rotate(1);
         P[1].link[3] = cube[4];

         P[2].mid = cube[2];
         P[2].link[0] = cube[0];
         P[2].link[1] = cube[3];
         P[2].link[2] = cube[5];
         P[2].link[3] = cube[1];

         P[3].mid = cube[3];
         P[3].link[0] = cube[0],P[3].link[0].rotate(1);
         P[3].link[1] = cube[4];
         P[3].link[2] = cube[5],P[3].link[2].rotate(3);
         P[3].link[3] = cube[2];

         P[4].mid = cube[4];
         P[4].link[0] = cube[0],P[4].link[0].rotate(2);
         P[4].link[1] = cube[1];
         P[4].link[2] = cube[5],P[4].link[2].rotate(2);
         P[4].link[3] = cube[3];

         P[5].mid = cube[5];
         P[5].link[0] = cube[2];
         P[5].link[1] = cube[3],P[5].link[1].rotate(1);
         P[5].link[2] = cube[4],P[5].link[2].rotate(2);
         P[5].link[3] = cube[1],P[5].link[3].rotate(3);

         for (int i = 0; i < 5; i++)
         {

             state ans;
             for (int j = 0; j < 3; j++)
             {
                 char ch;
                 int d;
                 scanf("%c%d", &ch, &d);
                 d--;
                 if (j == 0) 
                 {
                     ans.mid.C = ch;
                     ans.mid.dir = d;
                 }
                 else
                 {
                     ans.link[j].C = ch;
                     ans.link[j].dir = d;
                 }
             }
             getchar();
             ans.mid.rotate (2);
             ans.link[1].rotate(3);
             ans.link[2].rotate(1);
             ans.link[0].C = '*';
             ans.link[3].C = '*';
             if (Find(ans)) tot+=1, ret.push_back(1);
             else
                 ret.push_back(0);

         }
         printf("%d ", ctr);
         printf("%d", tot);
             for (int i = 0; i < 5; i++)
                 if (ret[i])
                     printf(" Y");
                 else
                     printf(" N");
             printf("\n");
     }

     return 0;
 }