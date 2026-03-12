#include <stdio.h>
int d[100005];
int n,m;
int main(){
	int need,value;
	scanf("%d%d", &n, &m);
	while(n--){
		scanf("%d%d", &need, &value);
		for(int i = need; i <= m; i++)
			if(d[i-need] + value > d[i])
				d[i] = d[i-need] + value;
	}
	printf("%d\n",d[m]);
	return 0;
}