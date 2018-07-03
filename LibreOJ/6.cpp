#include "interaction.h"
using namespace std;

vector<int>ans;
int binary(int idx)
{
	int l = 0,r = 1000000;
	int mid,res;
	while(l<=r)
	{
		mid = (l+r)>>1;
		res = guess(idx,mid);
		if(res>0){
			r = mid -1;
		}
		else if(!res) return mid;
		else l = mid + 1;
	}
	return l;
}
int main()
{
	int n = get_num();
	for(int i=0;i<n;i++)
	{
		ans.push_back(binary(i));
	}
	submit(ans);
	return 0;
}