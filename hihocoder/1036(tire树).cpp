#include <cstdio>
#include <cstring>
#include <queue>


int node_cnt;

struct TreeNode {
	int next[26];
	int trie;
	bool eow;
} node[1000000];

void node_insert(char *word);
void build_graph();
bool check(char *essay);

int main() {
	int N;
	char word[100010];
	char essay[1000010];
	memset(node, 0, sizeof(node));
	node_cnt = 0;

	scanf("%d", &N);
	while(N--) {
		scanf("%s", word);
		node_insert(word);
	}
	build_graph();
	scanf("%s", essay);
	if(check(essay))
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}

void node_insert(char *word) {
	int p, i, j;
	for(i = 0, p = 0; word[i]; i++) {
		j = word[i] - 'a';
		if(!node[p].next[j])
			node[p].next[j] = ++node_cnt;
		p = node[p].next[j];
	}
	node[p].eow = true;
}

void build_graph() {
	std::queue<int> q;
	int p, i;
	q.push(0);
	while(!q.empty()) {
		p = q.front();
		q.pop();
		if(node[node[p].trie].eow)
			node[p].eow = true;
		for(i = 0; i < 26; i++)
			if(node[p].next[i]) {
				q.push(node[p].next[i]);
				if(p)
				    node[node[p].next[i]].trie = node[node[p].trie].next[i];
			}
			else
				node[p].next[i] = node[node[p].trie].next[i];
	}
}

bool check(char *essay) {
	int i, p;
	for(i = 0, p = 0; essay[i]; i++){
		p = node[p].next[essay[i] - 'a'];
		if(node[p].eow)
			return true;
	}
	return false;
}
