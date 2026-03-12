#include<iostream>
#include<cstdio>
int main()
{
	int n,k,t,s,i;
	while(~scanf("%d",&n)){
		k=n;    
		t=0;  //Ê±¼ä 
		s=0; //Â¥²ã 
		if(n==0)break;
		while(n--){
			scanf("%d",&i);
			if(i-s>=0){
				t=t+6*(i-s);
				s=i;
			}
			if(s-i>=0){
				t=t+4*(s-i);
				s=i;
			} 
		}
		printf("%d\n",t+5*k);
	}
			
	
	return 0;
}