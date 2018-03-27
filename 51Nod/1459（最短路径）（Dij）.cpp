#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
const int inf = 0x3f3f3f3f;
int map[550][550];
int vis[550];
int val[550];
int dis[550];
int sum[550];
int main() {
	int n, m, s, e;
	scanf("%d %d %d %d", &n, &m, &s, &e);
	int i, j, k = 0;
	for(i = 0; i < n; i++) {
		scanf("%d", &val[i]);
	}
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			if(i == j) map[i][j] = 0;
			else map[i][j] = inf;
		}
	}
	int x, y, z;
	for(i = 0; i < m; i++) {
		scanf("%d %d %d", &x, &y, &z);
		map[x][y] = z;
		map[y][x] = z;
	}
	for(i = 0; i < n; i++) {  //初始化 
		vis[i] = 0;
		dis[i] = inf;
		sum[i] = 0;
	}
	dis[s] = 0;
	sum[s] = val[s];
	int min, v;
	for(i = 0; i < n; i++) {
		min = inf;
		v = 0;
		for(j = 0; j < n; j++) {
			if(vis[j] == 0) {
				if(min > dis[j]) {
					min = dis[j];
					v = j;
				}
			}
		}
		vis[v] = 1;
		for(j = 0; j < n; j++) {
			if(vis[j] == 0) {
				if(dis[j] > dis[v] + map[v][j]) {
					dis[j] = dis[v] + map[v][j];
					sum[j] = sum[v] + val[j];
				}
				else if(dis[j] == dis[v] + map[v][j]) {    //解题关键 
					sum[j] = max(sum[v] + val[j], sum[j]);
				}
			}
		}
	}
	printf("%d %d\n", dis[e], sum[e]);
	return 0;
}
