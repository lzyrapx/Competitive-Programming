#include <bits/stdc++.h>
using namespace std;
int tree[50010], n;

int lowbit(int x){ //得到pow(2, k), 其中k为x的二进制末尾0的个数即x二进制最低位1的值
    return x&(-x);
}

void update(int x, int d)//向上更新父节点及根节点,在x的位置加d 
{ 
    while(x<=n){
        tree[x]+=d;
        x+=lowbit(x);
    }
}

int sum(int x)//向下求和
{ 
    int ans=0;
    while(x>0){
        ans+=tree[x];
        x-=lowbit(x);
    }
    return ans;
}
pair<int, int> p[50010];
int main()
{
    
    int gg[50010], ans=0;
    scanf("%d", &n);
    for(int i=1; i<=n; i++)//hash
	{  
        scanf("%d", &p[i].first);
        p[i].second=i;
    }
    sort(p+1, p+n+1);
    for(int i=1; i<=n; i++){
        gg[p[i].second]=i;
    }
    for(int i=1; i<=n; i++){
        update(gg[i], 1); //因为x不能和自己组成逆序对，要加上，所以我们要先更新再求和，更新后sum(x)就包括了x了
        ans+=i-sum(gg[i]);//sum=x前面i-1个元素中比x小的个数 + 1
	}
    printf("%d\n", ans);
    return 0;
}