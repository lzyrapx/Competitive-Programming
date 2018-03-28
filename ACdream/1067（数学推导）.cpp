/*
* this code is made by LzyRapx
* Problem: 1067
* Verdict: Accepted
* Submission Date: 2017-06-07 17:15:39
* Time: 920MS
* Memory: 1664KB
*/
#include <bits/stdc++.h>
using namespace std;
 
//总三角形数减去钝角和直角三角形数
/*
分析：当3个点组成锐角三角形ABC时，圆心O一定在三角形内部，∠AOB , ∠BOC, ∠COA一定小于180度（∠AOB  +  ∠BOC + ∠COA = 360度）
(1)当N为偶数时，用1, 2 .... k ,  k+1,  .... , 2k来标记N个点(2K = N).  固定一个点,  如点A = 点k， 那么2k点是肯定不能选的了，因为 k, 2k组成一条直径。
所以剩下两个区间 [1， k-1],  [K+1, 2k-1].如果点B， 点C同处一个区间，那么ABC一定是一个钝角三角形，所以B，C一定不可处于同一区间。
设点B = 点x， x 属于[1, k-2];   点C=点y，y 属于[k+1, 2k-1];
在这样的情况下，y - x > k 才能使得ABC为锐角三角形  ==> (x, y)的取值有S =  0 + 1 + 2 + ... + (k - 2) = (k -1) * (k -2) /2  = (N/2 - 1) * (N / 2 - 2) / 2 ;
有N个点，每个三角形被重复计算3次，所以一共有 S * N / 3种；
 
(2)点N为奇数时， k = N / 2.  用0,  1 ... k ,  k + 1,  2k.
固定点A = 点0，则过点A的直径把N个点分成[1, k],   [k+1, 2k]两个部分。和(1)同理，可以令  点B = 点x , x 属于[1, k],  点C = 点y，  y 属于[k+1, 2k];
在这样的情况下，y - x <=  k 才能使得ABC为锐角三角形  ==> (x, y)的取值有S =  k + (k- 1) + ... + 1 = k  * (k +1)  /2  = (N/2) * (N / 2 + 1) / 2 ;
有N个点，每个三角形被重复计算3次，所以一共有 S * N / 3种；
综上：
N 为偶数时,ans = N *  (N/2 - 1) * (N / 2 - 2) / 6
N为奇数时，ans = N * (N/2) * (N / 2 + 1) / 6
*/
int main()
{
    long long n;
    int k=0;
    while(cin>>n)
    {
        k=0;
        if(n<=2)puts("0");
        else if(n==3)puts("1");
        else if(n%2==1)
        {
            k=n/2;
            cout<< n*k*(k+1)/6 <<endl;
        }
        else if(n%2==0)
        {
            k=n/2;
            cout<< n*(k-1)*(k-2)/6 <<endl;
        }
    }
    return 0;
}