/* java*/
/*import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n =sc.nextInt();
		for(int i=1;i<=n;i++){
			BigInteger a = sc.nextBigInteger();
			BigInteger b = sc.nextBigInteger();
			System.out.println("Case "+i+":");
			System.out.println(a+" + "+b+" = "+a.add(b));
			if(i!=n){
				System.out.println();
			}
		}
	}
}
*/

#include<stdio.h>
#include<string.h>
int main()
{
	char a[1000],b[1000],c[1001];
	int i,j=1,p=0,n,n1,n2;
	scanf("%d",&n);
    while(n)
	{
		scanf("%s %s",a,b);
		printf("Case %d:\n",j);
		printf("%s + %s = ",a,b);
		n1=strlen(a)-1;
		n2=strlen(b)-1;
		for(i=0;n1>=0||n2>=0;i++,n1--,n2--)
		{
			if(n1>=0&&n2>=0){ c[i]=a[n1]+b[n2]-'0'+p;}
			if(n1>=0&&n2<0){ c[i]=a[n1]+p;}
			if(n1<0&&n2>=0){ c[i]=b[n2]+p;}
			p=0;
			if(c[i]>'9'){ c[i]=c[i]-10;p=1;}
		}
		if(p==1){printf("%d",p);}
		while(i--)
		{ 
	   printf("%c",c[i]);}
		j++;
		if(n!=1){ printf("\n\n"); }
		else { printf("\n"); }
		n--;
	}
}