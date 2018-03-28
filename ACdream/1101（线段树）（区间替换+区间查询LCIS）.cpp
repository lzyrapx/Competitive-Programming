/*
* this code is made by LzyRapx
* Problem: 1101
* Verdict: Accepted
* Submission Date: 2017-07-09 15:23:04
* Time: 468MS
* Memory: 17584KB
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 123456;
int a[N], n, m;
struct Node{
    int l, r;
    int l_ele, r_ele;
    int l_len, len, r_len;
    Node(){}
    Node(int l, int r, int l_ele, int r_ele, int l_len, int len, int r_len){
        this->l = (l);
        this->r = (r);
        this->l_ele = (l_ele);
        this->r_ele = (r_ele);
        this->l_len = (l_len);
        this->len = (len);
        this->r_len = (r_len);
    }
    Node operator + (const Node &o) const{
        Node ret;
        ret.l = l, ret.r = o.r;
        ret.l_ele = l_ele, ret.r_ele = o.r_ele;
          
        ret.l_len = l_len;
        if(len == r - l + 1 && r_ele < o.l_ele) ret.l_len = len + o.l_len;
          
        ret.r_len = o.r_len;
        if(o.len == o.r - o.l + 1 && r_ele < o.l_ele) ret.r_len = o.len + r_len;
          
        ret.len = max(len, o.len);
        if(r_ele < o.l_ele) ret.len = max(ret.len, r_len + o.l_len);
          
        return ret;
    }
    void show(){
        cout << l << ' ' << r << ' ' << l_ele << ' ' << r_ele << ' ' << l_len << ' ' << len << ' ' << r_len << endl;
    }   
};
Node tree[N << 2];
int lazy[N << 2];
void push_down(int l, int r, int rt , int val)
{
    tree[rt] = Node(l, r, val, val, 1, 1, 1);
    lazy[rt] = val;
}
void build(int l,int r,int rt)
{
    if(l == r)
    {
        tree[rt] = Node(l, r, a[l], a[l], 1, 1, 1);
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, rt<<1);
    build(mid + 1, r, rt<<1|1);
    tree[rt] = tree[rt<<1] + tree[rt<<1|1];
}
Node query(int l, int r, int rt, int L, int R)
{
    if(l == L && r == R) return tree[rt];
    int mid = (l + r) >> 1;
    if(lazy[rt])
    {
        push_down(l, mid, rt<<1, lazy[rt]);
        push_down(mid + 1, r, rt<<1|1, lazy[rt]);
        lazy[rt] = 0;
    }
    if(R <= mid) return query(l, mid, rt<<1, L, R);
    else if(L > mid) return query(mid + 1, r, rt<<1|1, L, R);
    return query(l, mid, rt<<1, L, mid) + query(mid + 1, r, rt<<1|1, mid + 1, R);
}
void update( int l, int r, int rt, int L, int R, int val)
{
    if(l == L && r == R)
    {
        tree[rt] = Node(l, r, val, val, 1, 1, 1);
        lazy[rt] = val;
        return;
    }
    int mid = (l + r) >> 1;
    if(lazy[rt])
    {
        push_down(l, mid, rt<<1, lazy[rt]);
        push_down(mid + 1, r, rt<<1|1, lazy[rt]);
        lazy[rt] = 0;
    }
    if(R <= mid) update(l, mid, rt<<1, L, R, val);
    else if(L > mid) update(mid + 1, r, rt<<1|1, L, R, val);
    else
    {
        update(l, mid, rt<<1, L, mid, val);
        update(mid + 1, r, rt<<1|1, mid + 1, R, val);
    }
    tree[rt] = tree[rt<<1] + tree[rt<<1|1];
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
//  cout<<"finish"<<endl;
    build(1,n,1);
//  cout<<"finish"<<endl;
    int l,r,val;
    char op[2];
    for(int i=0;i<m;i++)
    {
        scanf("%s %d %d",op,&l,&r);
        if(op[0]=='Q')
        {
            printf("%d\n",query(1,n,1,l,r).len);
        }
        else
        {
            scanf("%d",&val);
            update(1,n,1,l,r,val);
        }
    }
    return 0;
}