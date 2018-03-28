#include <bits/stdc++.h>
using namespace std;
 
const int N(1e5+5);
typedef long long LL;
 
LL bit[N<<2];
int a[N], m[N], r[N], bit2[N<<2];
vector<int> Lt[N], Rt[N], op[N], b;
map<int,int> s;
 
void add(int x, int v, int n){
    for(; x<=n; bit[x]+=v, x+=x&-x);
}
 
LL sum(int x){
    LL res=0;
    for(; x; res+=bit[x], x-=x&-x);
    return res;
}
 
void Add(int x, int v, int n){
    for(; x<=n; bit2[x]+=v, x+=x&-x);
}
 
int Sum(int x){
    int res=0;
    for(; x; res+=bit2[x], x-=x&-x);
    return res;
}
 
int main(){
    int n, q;
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d%d%d", a+i, m+i, r+i);
    scanf("%d", &q);
    for(int l, r, t; q--; ){
        cin>>t>>l>>r;
        Lt[l].push_back(t);
        Rt[r].push_back(t);
    }
    s[0]++;
    LL ans=0;
    for(int i=1; i<=n; i++){
        for(auto &t: Rt[i-1]){
            if(--s[t]) continue;
            auto p=s.lower_bound(t);
            int pre, suc;
            pre=(--p)->first, ++p, op[i].push_back(pre-t);
            if(++p!=s.end())
                suc=p->first, op[i].push_back(t-suc), op[i].push_back(suc-pre), b.push_back(suc-pre);
            s.erase(--p);    //error-prone
        }
        for(auto &t: Lt[i]){
            if(s[t]++) continue;
            auto p=s.lower_bound(t);
            int pre, suc;
            pre=(--p)->first, ++p, op[i].push_back(t-pre), b.push_back(t-pre);
            if(++p!=s.end()) suc=p->first, op[i].push_back(suc-t), b.push_back(suc-t), op[i].push_back(pre-suc); 
        }
        if(s[0]>1) ans+=a[i];
        else{
            auto p=s.begin();
            if(++p!=s.end()){
                int t=p->first;
                ans+=min(a[i]+(LL)t*r[i], (LL)m[i])-min((LL)t*r[i], (LL)m[i]);  //error-prone
            }
        }
    }
    sort(b.begin(), b.end());
    auto e=unique(b.begin(), b.end());
    int size=e-b.begin();
    for(int i=1; i<=n; i++){
        for(int &x: op[i]){
            int id=upper_bound(b.begin(), e, abs(x))-b.begin(); //error-prone
            add(id, x, size);
            if(x<0) Add(id, -1, size);
            else Add(id, 1, size);
        }
        if(m[i]==0 || r[i]==0) continue;    //error-prone
        int t=(m[i]-1)/r[i]+1;
        int id=lower_bound(b.begin(), e, t)-b.begin();
        ans+=(LL)(Sum(size)-Sum(id))*m[i];
        ans+=sum(id)*r[i];
    }
    printf("%lld\n", ans);
    return 0;
}