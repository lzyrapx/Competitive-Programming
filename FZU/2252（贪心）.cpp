#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
ll a[10],b[10],c[10];
int main()
{
    ll ab,ac,bc;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>a[0]>>b[0]>>c[0];
		cin>>ab>>ac>>bc;
        for(int i=1; i<=10; i++)
        {
            a[i]=a[0];
            b[i]=b[0];
            c[i]=c[0];
        }
        ll ans=0,minn,min2;
        ll x;
        ll f;
        ll flag;
        
        //1  ab bc
        x=min(a[0],b[0]);
        f=x*ab;
        a[0]=a[0]-x;
        b[0]=b[0]-x;
        
        x=min(b[0],c[0]);
        f+=x*bc;
        ans=max(ans,f);

        //2  ab ac
        x=min(a[1],b[1]);
        f=x*ab;
        a[1]=a[1]-x;
        b[1]=b[1]-x;
        
        x=min(a[1],c[1]);
        f+=x*ac;
        ans=max(ans,f);

        //3 ac bc
        x=min(a[2],c[2]);
        f=x*ac;
        a[2]=a[2]-x;
        c[2]=c[2]-x;
        
        x=min(b[2],c[2]);
        f+=x*bc;
        ans=max(ans,f);
        
        //4 ac ab
        x=min(a[3],c[3]);
        f=x*ac;
        a[3]=a[3]-x;
        c[3]=c[3]-x;
        
        x=min(b[3],a[3]);
        f+=x*ab;
        ans=max(ans,f);
        
        //5 bc ab
        x=min(c[4],b[4]);
        f=x*bc;
        c[4]=c[4]-x;
        b[4]=b[4]-x;
        
        x=min(b[4],a[4]);
        f+=x*ab;
        ans=max(ans,f);

        //6 bc ac
        x=min(c[5],b[5]);
        f=x*bc;
        c[5]=c[5]-x;
        b[5]=b[5]-x;
        
        x=min(a[5],c[5]);
        f+=x*ac;
        ans=max(ans,f);
   	
   		//k1分给ab,a[6]-k1分ac,b[6]-k1分bc
        ll k1=(a[6]+b[6]-c[6])/2;
        if(k1>=0&&a[6]>=k1&&b[6]>=k1)
        {
            
            minn=min(c[6]-(a[6]-k1),b[6]-k1);
            f=k1*ab+(a[6]-k1)*ac+minn*bc;
         
            ans=max(ans,f);
            min2=min(c[6]-(b[6]-k1),a[6]-k1);
            f=k1*ab+min2*ac+(b[6]-k1)*bc;
            
            ans=max(ans,f);
        }

        //k2分给ac,a[7]-k2分ab,c[7]-k2分bc
        ll k2=(a[7]+c[7]-b[7])/2;
        if(k2>=0&&a[7]>=k2&&c[7]>=k2)
        {
          
            minn=min(b[7]-(a[7]-k2),c[7]-k2);
            f=k2*ac+(a[7]-k2)*ab+minn*bc;
           
            ans=max(ans,f);
            min2=min(b[7]-(c[7]-k2),a[7]-k2);
            f=k2*ac+min2*ab+(c[7]-k2)*bc;
        
            ans=max(ans,f);
        }

       //k3分给bc,b[8]-k3分ab,c[8]-k3分ac
        ll k3=(c[8]+b[8]-a[8])/2;
        if(k3>=0&&b[8]>=k3&&c[8]>=k3)
        {
            
            minn=min(a[8]-(b[8]-k3),c[8]-k3);
            f=k3*bc+(b[8]-k3)*ab+minn*ac;
           
            ans=max(ans,f);
            min2=min(a[8]-(c[8]-k3),b[8]-k3);
            f=k3*bc+min2*ab+(c[8]-k3)*ac;
            
            ans=max(ans,f);
        }
        cout<<ans<<endl;
    }
    return 0;
}