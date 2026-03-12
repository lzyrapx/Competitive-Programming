#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
int n;
long long K; 
map<long long,long long>M;
const int N=1e7;
int prime[N+10],pd[N+10],miu[N+10],len,pre[N+10];
void make(){
    miu[1]=1;
    for (int i=2;i<=N;i++){
        if (pd[i]==0){
            miu[i]=-1; prime[++len]=i;
        }
        for (int j=1;j<=len&&i*prime[j]<=N;j++){
            int k1=i*prime[j]; pd[k1]=1;
            if (i%prime[j]==0) break; else miu[k1]=-miu[i];
        }
    }
    for (int i=1;i<=N;i++) pre[i]=miu[i]+pre[i-1];
}
long long get(long long k1){
    if (k1<=N) return pre[k1];
    if (M[k1]) return M[k1];
    long long ne=0,ans=0;
    for (long long i=2;i<=k1;i=ne+1){
        ne=k1/(k1/i); ans+=(ne-i+1)*get(k1/i);
    }
    M[k1]=1-ans; return 1-ans;
}
long long get1(long long k1){
    long long ans=0;
    for (int i=1;1ll*i*i<=k1;i++) ans+=miu[i]*(k1/i/i);
    return ans;
}
long long get(int k1,long long k2){
    long long A=get1(k2);
    if (k1==0) return k2-A;
    long long B=get(k2);
    //cout<<"fa "<<k1<<" "<<k2<<" "<<A<<" "<<B<<endl;
    if (k1==1) return (A+B)/2; else return (A-B)/2;
}
void solve(){
    scanf("%d%I64d",&n,&K);
    long long l=0,r=K*5,wl=0,wr=get(n,r);
//    cout<<r<<" "<<wr<<endl;
    while (l<r-1){
        long long mid=(double)(K-wl)/(double)(wr-wl)*(r-l)+l;
        mid=min(max(mid,l+1),r-1);
        long long now=get(n,mid);
        if (now>=K){
            r=mid,wr=now;
        } else l=mid,wl=now;
    }
    //cout<<get(1,661290)<<endl;
    //cout<<get(1,661291)<<endl;
    cout<<r<<endl;
}
int main(){
    make();
    int t; scanf("%d",&t);
    for (int i=1;i<=t;i++){
        solve();
    }
    return 0;
}