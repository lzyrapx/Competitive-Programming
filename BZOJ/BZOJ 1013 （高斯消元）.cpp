/**************************************************************
    Problem: 1013
    User: LzyRapx
    Language: C++
    Result: Accepted
    Time:20 ms
    Memory:13184 kb
****************************************************************/
 
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1234;
 
// https://www.lydsy.com/JudgeOnline/problem.php?id=1013
 
const double eps=1e-8;
int n;
double a[maxn][maxn];
bool Gauss()
{
    int r;
    double f;
    for(int i = 0;i < n; i++)
    {
        r=i;
        for(int j=i+1;j<n;j++) {
          if(fabs(a[j][i])>fabs(a[r][i])) r=j;
        }
        if(fabs(a[r][i])<eps) return false;
        if(r!=i) {
          for(int j=0;j<=n;j++) swap(a[r][j],a[i][j]);
        }
        for(int k=i+1;k<n;k++)
        {
            f=a[k][i]/a[i][i];
            for(int j=i;j<=n;j++) {
              a[k][j]-=f*a[i][j];
            }
        }
    }
    for(int i=n-1;i>=0;--i)
    {
        for(int j=i+1;j<n;++j) a[i][n]-=a[j][n]*a[i][j];
        a[i][n]/=a[i][i];
    }
    return true;
}
int main(int argc, char const *argv[]) {
    // freopen("in.txt","r",stdin);
    std::cin >> n;
    n++;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - 1; j++) {
            double x;
            std::cin >> x;
            a[i][j] = -2.0 * x;
            a[i][n-1] = 1.0;
            a[i][n] -=  1.0 * x * x;
        }
    }
    // std::cout << "ok" << '\n';
    if(Gauss()) {
        for(int i = 0; i < n - 1; i++) {
            printf("%.3lf ",a[i][n]);
        }
        std::cout << '\n';
    }
    return 0;
}
﻿