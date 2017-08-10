#include "bits/stdc++.h"
using namespace std;

#define debug(args...) // fprintf(stderr, args)

const int maxn = 1e5 + 10;
const int N = 1e9;

int t, n;
long long a[maxn], k;

vector <int> adj[maxn];
int p[maxn];

int root;

typedef struct node * pnode;

struct node {
	int sum;
	pnode l, r;

	node() {
		sum = 0;
		l = r = NULL;
	}
};

pnode seg = new node();

void free_seg(pnode idx) {
	if(idx->l) free_seg(idx->l);
	if(idx->r) free_seg(idx->r);
	free(idx); 
}

int sum_seg(pnode &idx) {
	if(!idx) return 0;
	return idx->sum;
}

void add(pnode &idx, int i, int j, int pos, int val) {
	if(i == j) {
		idx->sum += val;
		return;
	}

	int mid = (i + j) >> 1;

	if(pos <= mid) {
		if(!idx->l) idx->l = new node();
		add(idx->l, i, mid, pos, val);
	}
	else {
		if(!idx->r) idx->r = new node();
		add(idx->r, mid + 1, j, pos, val);
	}

	idx->sum = sum_seg(idx->l) + sum_seg(idx->r);
}

long long ans;

long long get(pnode &idx, int i, int j, int ini, int fim) {
	if(!idx) return 0;

	if(i > j || j < ini || fim < i) return 0;

	if(ini <= i && j <= fim) return idx->sum;

	int mid = (i + j) >> 1;

	return get(idx->l, i, mid, ini, fim) + get(idx->r, mid + 1, j, ini, fim);
}

long long bs(long long a) {
	long long st = 0;
	long long ed = N;

	for(int i = 0; i < 70; ++i) {
		long long mid = (st + ed) / 2LL;
		if(a * mid <= k) st = mid;
		else ed = mid;
	}	

	return st;
}

void dfs(int v) {

	long long pos = bs(a[v]);

	debug("node(%d) %lld\n", v, pos);

	ans += get(seg, 0, N, 0, pos);
	add(seg, 0, N, a[v], +1);

	for(int i = 0; i < adj[v].size(); ++i) {
		int u = adj[v][i];
		debug("%d -> %d\n", v, u);
		dfs(u);
	}

	add(seg, 0, N, a[v], -1);
}

int main() {
	scanf("%d", &t);

	while(t--) {
		scanf("%d %lld", &n, &k);

		for(int i = 0; i < n; ++i) {
			scanf("%lld", &a[i]);
			adj[i].clear();
			p[i] = 0;
		}

		for(int i = 0; i < n - 1; ++i) {
			int a, b;
			scanf("%d %d", &a, &b);

			--a, --b;

			adj[a].push_back(b);
			p[b] = 1;
		}

		free_seg(seg);
		seg = new node();

		for(int i = 0; i < n; ++i)
			if(!p[i]) {
				root = i;
				break;
			}

		debug("root = %d\n", root);

		ans = 0;
		dfs(root);

		printf("%lld\n", ans);
	}

	return 0;
}