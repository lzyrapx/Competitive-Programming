/*
题意：给定序列A，含n个数。和一个数m；
有一个X序列{x1,x2,x3}，x1,x2,x3来自[1,m]区间内的数。

设：f(k)表示两个序列的最长公共子序列为k；

求序列X和A满足f(0),f(1),f(2),f(3)的X各有多少种。

思路：f(0)易求。计算出n个数中在m范围内的不同数的数量为cnt，然后计算(m-cnt)^3即可。

对n个数中<=m的数，离散化。

要求f(1),f(2),f(3);
f(3)的X序列内的数一定是n个数中获得。
f(2)的X序列内的数有两种来源，一种是三个数从n个数中获得，然后Longest Common Subsequence为2；
另一种是其中两个是n个数中获得，然后Longest Common Subsequence为2，另外一个是<=m的不包含n个数的数中获得。
f(1)的X序列内的数有三种来源，一种是3个数从n个数中获得，然后Longest Common Subsequence为1；
另一种是两个数从n个数中获得，然后Longest Common Subsequence为1；另外一个是是<=m的不包含n个数的数中获得。
另一种是其中一个是n个数中获得，然后Longest Common Subsequence为1，另外二个是<=m的不包含n个数的数中获得。

设：cnt表示n个数中<=m的数。kind表示n个数中<=m的不同数的种类。m-kind表示不包含n个数的数的种数。

枚举x1,x2,x3全是n个数组成的X序列，所有xi都枚举所有的n个数。

这些序列包含f(3),f(2)第一种来源，f(1)第一种来源的情况数。计算方法：一种是常规的Longest Common Subsequence 的dp求法，但是总时间复杂度为O(N^4);
更好的做法是：预处理next[i][j]表示i这个位置右边第一次出现j这个数的位置。那么可以O(1)判断X序列的Longest Common Subsequence为k。把它们更新到f(k)中。
flag[a[i]][a[j]][a[k]]表示这个序列可以匹配的最大LCS；取最值，最后遍历计算即可。

剩下要求f(2)的第二种来源,f(1)的第二种来源和第三种来源。
f(2)第二种来源：三种可能(x1,x2),(x2,x3),(x1,x3)位置，Longest Common Subsequence为2，另一个位置为m-kind中取。 其实情况数是一样的。f(2) += 3*Q(cnt)*(m-kind);
Q(cnt)表示cnt个数中找到与A序列的Longest Common Subsequence为2的序列数量。暴力枚举两个位置，同上面说的方法。

f(1)第二种来源：三种可能(x1,x2),(x2,x3),(x1,x3)位置,但是Longest Common Subsequence为1；另外一个位置从m-kind中取。 f(1) += 3*P(cnt)*(m-kind);
f(1)第三种来源：三种可能x1,x2,x3位置相同，另外两个位置为m-kind中取。f(1) += 3*kind*(m-kind)*(m-kind);


思考：为什么要用next[i][j]表示i这个位置右边第一次出现j这个数的位置。而不是直接next[i][j]表示j这个数是否在i的右边。
假设： 2 2
那么枚举出来2 2 2. 如果用后者所述定义，那么答案就是3了。实际上只能是2.
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> P;
const int maxn = 1e5+100;
int flag[202][202][202];
int sign[202][202];
int mark[1000005];
int n, m;
int cnt , kind;
LL f[4];
int a[202], z;
int Next[202][202];

set<int> se;

void NextInit()
{
    for(int i = 0; i < z; i++)
	{
        for(int j = i+1; j < z; j++)
		{
            if(Next[i][a[j]]==-1)
			{
                Next[i][a[j]] = j;
            }
        }
    }
}
void lisan()
{
    int cnt = 1;
    set<int>::iterator it;
    for(it = se.begin(); it!=se.end(); it++)
	{
        mark[*it] = cnt;
        cnt++;
    }
    for(int i = 0; i < z; i++)
	{
        a[i] = mark[a[i]];
    }
}

int cal(int i,int j,int k)//O(1)查询 
{
    if(Next[i][a[j]]==j&&Next[j][a[k]]==k) return 3;
    if(Next[i][a[j]]==j) return 2;
    if(Next[j][a[k]]==k) return 2;
    if(Next[i][a[k]]==k) return 2;
    return 1;
}
/*
f(3)的X序列内的数一定是n个数中获得。

f(2)的 X序列内的数有两种来源，一种是三个数从n个数中获得，然后 LCS为2；
另一种是其中两个是n个数中获得，然后LCS为2，另外一个是<=m的不包含n个数的数中获得。

f(1)的X序列内的数有三种来源，一种是3个数从n个数中获得，然后 LCS为 1；
另一种是两个数从 n个数中获得，然后 LCS 为 1；另外一个是是<=m的不包含n个数的数中获得。
另一种是其中一个是 n个数中获得，然后 LCS 为 1，另外二个是<=m的不包含n个数的数中获得。
*/
void solve()
{
	//计算出n个数中在m范围内的不同数的数量为cnt，然后计算(m-cnt)^3即为 f(0)。 
	
    kind = se.size();//n个数中<=m的不同数的种类
    cnt = z;
    LL temp = m-kind;//不包含n个数的数的种数
    f[0] = 1LL*temp*temp*temp;
    
    //枚举三层循环所有序列。
   
	//flag[a[i]][a[j]][a[k]]表示这个序列可以匹配的最大LCS；取最值，最后遍历计算即可。
	
	//三个数从n个数中获得 
    for(int i = 0; i < z; i++)
	{
        for(int j = 0; j < z; j++)
		{
            for(int k = 0; k < z; k++)
			{
                int len = cal(i,j,k);
                flag[a[i]][a[j]][a[k]] = max(flag[a[i]][a[j]][a[k]],len);
            }
        }
    }

    se.clear();//清空原先没有离散的数据
    
    for(int i = 0; i < z; i++)
	{
        se.insert(a[i]);
    }
    
    set<int>::iterator it, it1, it2;
    for(it = se.begin(); it!=se.end(); it++)
	{
        for(it1 = se.begin(); it1!=se.end(); it1++)
		{
            for(it2 = se.begin(); it2!=se.end(); it2++)
			{
                f[flag[*it][*it1][*it2]]++;
            }
        }

    }

    //枚举两层循环.
    int cnt2, cnt1;
    for(int i = 0; i < z; i++)
	{
        for(int j = 0; j < z; j++)
		{
            int len;
            if(Next[i][a[j]]==j)
			{
				len = 2;
			}
            else
            {
            	len = 1;
			}
		
            sign[a[i]][a[j]]= max(sign[a[i]][a[j]],len);
        }
    }
    cnt1 = cnt2 = 0;
    for(it = se.begin(); it!=se.end(); it++)
	{
        for(it1 = se.begin(); it1!=se.end(); it1++)
		{
            if(sign[*it][*it1]==2)//LCS为 2 的序列数量 
			{
                cnt2++;
            }
			else cnt1++;
        }
    }

    f[2] += 1LL*3*cnt2*(m-kind);
    f[1] += 1LL*3*cnt1*(m-kind);
    ///f(1)第三种来源;
    f[1] += 1LL*3*kind*(m-kind)*(m-kind);
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        z = 0;
        for(int i = 0; i < n; i++) {
            scanf("%d",&a[z]);
            if(a[z]<=m) z++;//n个数中<=m的数
        }
        memset(f, 0, sizeof f);
   		memset(Next, -1, sizeof Next);
    	memset(flag, 0, sizeof flag);
    	memset(sign, 0, sizeof sign);
    	se.clear();
        for(int i = 0; i < z; i++)
		{
            se.insert(a[i]);
        }
        lisan();//对n个数中<=m的数，离散化。
		//预处理next[i][j]表示i这个位置右边第一次出现j这个数的位置。
		//那么可以O(1)判断X序列的Longest Common Subsequence为k。把它们更新到f(k)中。 
        NextInit();
        solve();
        printf("%I64d %I64d %I64d %I64d\n",f[0], f[1], f[2], f[3]);
    }
    return 0;
}