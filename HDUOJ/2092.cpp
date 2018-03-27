#include<stdio.h>
int main(){
	int i,m,n;
	while(scanf("%d%d",&m,&n)==2&&(m!=0||n!=0)){
		for(i=-9999;i<10000;i++){   //±©Á¦
			if(i*(m-i)==n){ 
				printf("Yes\n");
				break;
			}
		}
		if(i==10000)
			printf("No\n");
	}
	return 0;
}