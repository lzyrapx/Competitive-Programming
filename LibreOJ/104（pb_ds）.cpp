#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
//tree<ll,null_mapped_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>rbt;
tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> rbt;
int n;
ll k,ans;
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
} 
int main()
{
    n=read();
    for(int i=1,opt;i<=n;i++){
        opt=read();k=read();
        if(opt==1) rbt.insert((k<<20)+i);//插入
        if(opt==2) rbt.erase(rbt.lower_bound(k<<20));//删除
        if(opt==3) printf("%d\n",rbt.order_of_key(k<<20)+1); //查询 x 数的排名
        if(opt==4) ans=*rbt.find_by_order(k-1),printf("%lld\n",ans>>20);//查询排名为x的数
        if(opt==5) ans=*--rbt.lower_bound(k<<20),printf("%lld\n",ans>>20); //前驱
	    if(opt==6) ans=*rbt.lower_bound(k+1<<20),printf("%lld\n",ans>>20); // 后继 //AC
       // if(opt==6) ans=*rbt.upper_bound((k<<20)+n),printf("%lld\n",ans>>20);//AC
    }
    return 0;
}