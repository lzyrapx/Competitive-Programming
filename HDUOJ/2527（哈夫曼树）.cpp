#include<bits/stdc++.h>
using namespace std;
string str;
int k = 0; //叶子数量 
int m = 0; //叶子总数量 
int fa[123456],Left[123456],Right[123456];
int tot;
int weight[123456]; //权重 

//哈弗曼树本质上就是每次将最小的两个数相加，
//在与其他数进行比较将目前最小的两个数相加即可
//也可以用优先队列做 
void Huffman()
{
	int son_1,son_2;
//	int i;
	int small_one,small_two;
	for(int i=k;i<m;i++)
	{
		son_1 = son_2 = -1;
		small_one = small_two = 0x3f3f3f3f;
		for(int j=0;j<i;j++)
		{
			if(fa[j] == -1)
			{
				if(weight[j] < small_one)
				{
					small_two = small_one;
					small_one = weight[j];
					son_2 = son_1;
					son_1 = j;
				}
				else if(weight[j] < small_two)
				{
					small_two = weight[j];
					son_2 = j;
				}
			}
		}
		fa[son_1] = fa[son_2] = i;
		fa[i] = -1;
		Left[i] = son_1;
		Right[i] = son_2;
		weight[i] = small_one + small_two;
		tot += weight[i];
	}
	
}
//求除了叶子结点之外，其余结点的权值之和。   
set<char>st;
int main()
{
	int n;
	int t;
	int tmp[34];
	cin>>t;
	int limit = 0;
	while(t--){
		memset(tmp,0,sizeof(tmp));
		cin>>n>>str;
		for(int i=0;str[i];i++){
			++tmp[str[i]-'a'];
		//	st.insert(str[i]);
			limit = i;
		}
//		cout<<"len="<<str.length()<<endl;
//		if(st.size()==1)
//		{
//			if(str.length()<=n)puts("yes");
//			else puts("no");
//			continue;
//		}
		//cout<<"li="<<limit<<endl;
	//	如果只有一个结点，哈夫曼树建不起来，需要特判 
		//只有一种元素,tmp[str[0]]只有一种   
		if (tmp[str[0]-'a']==limit+1){ 
            if (limit+1 <= n) puts("yes");  
            else puts("no");  
            continue;  
        }  
		k = 0;
		for(int i=0;i<26;i++)
		{
			if(tmp[i])
			{
				weight[k++] = tmp[i];
			}
		}
		memset(fa,-1,sizeof fa);
		memset(Left,-1,sizeof(Left));
		memset(Right,-1,sizeof(Right));
		m = k+k-1;
		tot = 0;
		Huffman();
		if(tot<=n){
			puts("yes");
		}else
		{
			puts("no");
		}
		
	}
	return 0;
} 