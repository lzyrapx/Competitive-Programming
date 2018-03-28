#pragma comment(linker, "/STACK:102400000,102400000")
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <string>
using namespace std;
typedef pair<int,int> Pii;
typedef long long LL;
typedef unsigned long long ULL;
typedef double DBL;
typedef long double LDBL;
const int maxn=1e4+10;
//const int maxn=10;

char A[maxn], B[maxn];
bitset<maxn> posA[26], posB[26], 
Ap[maxn], Bp[maxn], ans, tem, pre[maxn];
/*
利用一个 bitset，先预处理出 26个字母在 A，B串的分布 
Ap[i][j]表示 A串长度为 i的前缀能在 B串的 j位置找到匹配 Bp
同理，Bp[i][j]为 B串长度为 i的前缀能在 A串的 j位置匹配
接下在 A串中枚举后缀开始的位置 i，利用二分以及 Bp来判断 
A串从 i位置开始，最远能在 B串中匹配到什么位置 
然后把 Ap[i-1]的这些位置取出来，移位一下， 
就能得到从 i位置拆开能对答案的哪些位置造成贡献， 
最后或到答案上即可
*/
int main()
{
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    #endif

    for(int i=1; i<maxn; i++) pre[i] = pre[i-1].set(i-1);
    while(~scanf(" %s %s", A, B))
    {
        int N=strlen(A);
        for(int i=0; i<26; i++) posA[i].reset(), posB[i].reset();

        for(int i=0; i<N; i++)
        {
            posA[A[i]-'a'][i] = 1;
            posB[B[i]-'a'][i] = 1;
        }

        Ap[0] = posB[A[0]-'a'];
        Bp[0] = posA[B[0]-'a'];
        for(int i=1; i<N; i++) Bp[i] = Bp[i-1] & (posA[B[i]-'a']>>i);

        ans.reset(); tem.reset();
        bool all = A[0]==B[0];
        if(all) ans[0]=1;
        for(int i=1; i<N; i++)
        {
            Ap[i] = Ap[i-1] & (posB[A[i]-'a']>>i);
            int l=0, r=N-1;
            while(l<r)
            {
                int mid=(l+r+1)>>1;
                if(!Bp[mid][i]) r=mid-1;
                else l=mid;
            }
            all &= A[i]==B[i];
            if(all) ans[i]=1;
            if(l==0 && A[i] != B[0]) continue;
            ans |= (Ap[i-1]&pre[l+1]) << (i-1);
        }
        for(int i=0; i<N; i++) putchar(ans[i]+'0');
        puts("");
    }
    return 0;
}