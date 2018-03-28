#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 500001;
int t, n, m, tot, que[maxn];
char op[maxn];
pair<int, int> a[maxn];
LL sta, ans;
struct Segment {
//	LL len : 20, sum : 40, zero : 1;
//	LL min : 21, max : 21, tag : 21;
	int min,max,tag,len;
	LL sum;
	bool zero; 
} seg[maxn << 1];
inline int seg_idx(int L, int R) {
	return (L + R) | (L < R);
}
void seg_init(int L, int R) {
	int rt = seg_idx(L, R);
	seg[rt].sum = seg[rt].min = seg[rt].max = seg[rt].tag = seg[rt].zero = 0;
	seg[rt].len = que[R + 1] - que[L];
	if(L == R)
		return;
	int M = (L + R) >> 1;
	seg_init(L, M);
	seg_init(M + 1, R);
}
inline void seg_up(int rt, int lch, int rch) {
	seg[rt].sum = seg[lch].sum + seg[rch].sum;
	seg[rt].min = min(seg[lch].min, seg[rch].min);
	seg[rt].max = max(seg[lch].max, seg[rch].max);
}
inline void seg_down(int rt, int lch, int rch) {
	if(seg[rt].zero) {
		seg[lch].sum = seg[lch].min = seg[lch].max = seg[lch].tag = 0;
		seg[lch].zero = 1;
		seg[rch].sum = seg[rch].min = seg[rch].max = seg[rch].tag = 0;
		seg[rch].zero = 1;
		seg[rt].zero = 0;
	}
	if(seg[rt].tag) {
		seg[lch].sum += (LL)seg[lch].len * seg[rt].tag;
		seg[lch].min += seg[rt].tag;
		seg[lch].max += seg[rt].tag;
		seg[lch].tag += seg[rt].tag;
		seg[rch].sum += (LL)seg[rch].len * seg[rt].tag;
		seg[rch].min += seg[rt].tag;
		seg[rch].max += seg[rt].tag;
		seg[rch].tag += seg[rt].tag;
		seg[rt].tag = 0;
	}
}
void seg_add(int L, int R, int l, int r, int v) {
	int rt = seg_idx(L, R);
	if(l <= L && R <= r) {
		seg[rt].sum += (LL)seg[rt].len * v;
		seg[rt].min += v;
		seg[rt].max += v;
		seg[rt].tag += v;
		return;
	}
	int M = (L + R) >> 1, lch = seg_idx(L, M), rch = seg_idx(M + 1, R);
	seg_down(rt, lch, rch);
	if(l <= M)
		seg_add(L, M, l, r, v);
	if(M < r)
		seg_add(M + 1, R, l, r, v);
	seg_up(rt, lch, rch);
}
void seg_erase_left(int L, int R) {
	int rt = seg_idx(L, R);
	if(seg[rt].max < 0) {
		sta += seg[rt].sum;
		seg[rt].sum = seg[rt].min = seg[rt].max = seg[rt].tag = 0;
		seg[rt].zero = 1;
	} else if(seg[rt].min < 0) {
		int M = (L + R) >> 1;
		int lch = seg_idx(L, M), rch = seg_idx(M + 1, R);
		seg_down(rt, lch, rch);
		seg_erase_left(L, M);
		if(seg[rch].min < 0)
			seg_erase_left(M + 1, R);
		seg_up(rt, lch, rch);
	}
}
void seg_erase_right(int L, int R) {
	int rt = seg_idx(L, R);
	if(seg[rt].min > 0) {
		seg[rt].sum = seg[rt].min = seg[rt].max = seg[rt].tag = 0;
		seg[rt].zero = 1;
	} else if(seg[rt].max > 0) {
		int M = (L + R) >> 1, lch = seg_idx(L, M), rch = seg_idx(M + 1, R);
		seg_down(rt, lch, rch);
		if(seg[lch].max > 0)
			seg_erase_right(L, M);
		seg_erase_right(M + 1, R);
		seg_up(rt, lch, rch);
	}
}
void seg_calc(int L, int R) {
	int rt = seg_idx(L, R);
	if(L == R) {
		sta += seg[rt].sum;
		ans = min(ans, sta);
		return;
	}
	int M = (L + R) >> 1, lch = seg_idx(L, M), rch = seg_idx(M + 1, R);
	seg_down(rt, lch, rch);
	seg_calc(L, M);
	seg_calc(M + 1, R);
	seg_up(rt, lch, rch);
}
int main()
{
	scanf("%d", &t);

	while(t--) {
		scanf("%d%d", &n, &m);
		
		for(int i = 1; i < n; ++i) {
			char buf[3];
			scanf("%s", buf);
			op[i]  = buf[0];
		}
		for(int i = 1; i <= m; ++i) {
			scanf("%d%d", &a[i].second, &a[i].first);
			que[i] = a[i].second;
		}
		sort(a + 1, a + m + 1);
		sort(que + 1, que + m + 1);
		tot = unique(que + 1, que + m + 1) - que - 1;
		if(tot == 1) {
			puts("0");
			continue;
		}
		sta = 0;
		seg_init(1, tot - 1);
		for(int i = 1, j = 1; i <= n; ++i) {
			int coeff = 0, las;
			for(int k = j; k <= m && a[k].first == i; ++k, --coeff) {
				sta += a[k].second - que[1];
				a[k].second = lower_bound(que + 1, que + tot + 1, a[k].second) - que;
			}
			for(las = 1; j <= m && a[j].first == i; ++j, coeff += 2) {
				if(las < a[j].second)
					seg_add(1, tot - 1, las, a[j].second - 1, coeff);
				las = a[j].second;
			}
			if(las < tot)
				seg_add(1, tot - 1, las, tot - 1, coeff);
			if(i < n)
			op[i]=='<'? seg_erase_right(1, tot - 1) : seg_erase_left(1, tot - 1);
		}
		ans = sta;
		seg_calc(1, tot - 1);
		printf("%lld\n", ans);
	}
	return 0;
}