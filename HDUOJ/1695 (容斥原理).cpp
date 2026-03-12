#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100010;
ll euler[N];
int num[N];
int p[N][20];
void init()//欧拉函数phi() 
{
	euler[1]=1;
	for(int i=2;i<N;i++){
		if(!euler[i]){
			for(int j=i;j<N;j+=i){ //注意是 j+=i 
				if(!euler[j])euler[j]=j;
				euler[j] = euler[j]*(i-1)/i;
				p[j][num[j]++] = i;
				//cout<<"i="<<i<<endl;
			}
		}
		euler[i] += euler[i-1];
	}
	//for(int i=1;i<=10;i++)cout<<euler[i]<<endl;

}
int solve(int b,int n)//区间中与 b 不互质的个数
{
	int ans=0;
	for(int i = 1; i < (1<<num[b]); i++){
		int cnt = 0;
		int m = 1;
		for(int j = 0; j< num[b];j++){
			if((1<<j) & i){
				cnt++;
				m *= p[b][j]; //p[b][j]是质数 
			}
		}
		//奇加偶减 
		if(cnt & 1) ans += n/m;
		else ans -= n/m;
	}
	return ans;
}
int main()
{
	int t,a,b,c,d;
	int k;
	init();
	//cout<<"finish"<<endl; 
	scanf("%d",&t);
	int cas=1;
	while(t--)
	{
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
		printf("Case %d: ",cas++);
		if(k==0){
			cout<<"0"<<endl;
			continue;
		}
		if(b>d)swap(b,d);
		b /= k;
		d /= k;
		ll ans=euler[b];
		for(int i = b + 1; i <= d;i++){
			ans += b-solve(i,b);
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
2
1 3 1 5 1
1 11014 1 14409 9
*/