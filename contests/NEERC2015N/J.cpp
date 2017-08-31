#include "bits/stdc++.h"
using namespace std;

#define debug(args...) fprintf(stderr, args)

const int maxn = 5e4 + 10;
const long long INF = 1e18;

int n, t;
long long d[maxn], p[maxn];

struct node
{
    long long lazy, Min;

    void merge(node L, node R) {
	Min = min(L.Min, R.Min);
    }

} seg[4 * maxn];

void build(int idx, int i, int j) {
    if(i == j) {
	seg[idx].Min = 0;
	seg[idx].lazy = 0;
	return;
    }

    int mid = (i + j) >> 1;
    int left = idx << 1;
    int right = left | 1;

    build(left, i, mid);
    build(right, mid + 1, j);

    seg[idx].merge(seg[left], seg[right]);
    seg[idx].lazy = 0;
}

void refresh(int idx, int i, int j) {
    if(!seg[idx].lazy)
	return;

    int left = idx << 1;
    int right = left | 1;

    if(i != j) {
	seg[left].lazy += seg[idx].lazy;
	seg[right].lazy += seg[idx].lazy;
    }

    seg[idx].Min += seg[idx].lazy;
    seg[idx].lazy = 0;
}

void update(int idx, int i, int j, int ini, int fim) {
    refresh(idx, i, j);

    if(i > j || j < ini || fim < i)
	return;

    if(ini <= i && j <= fim) {
	seg[idx].lazy += 1;
	refresh(idx, i, j);
	return;
    }

    int mid = (i + j) >> 1;
    int left = idx << 1;
    int right = left | 1;

    update(left, i, mid, ini, fim);
    update(right, mid + 1, j, ini, fim);

    seg[idx].merge(seg[left], seg[right]);
}

void change(int idx, int i, int j, int pos, long long val) {
    refresh(idx, i, j);

    if(i == j) {
	seg[idx].Min += val;
	return;
    }

    int mid = (i + j) >> 1;
    int left = idx << 1;
    int right = left | 1;

    if(pos <= mid)
	change(left, i, mid, pos, val);
    else
	change(right, mid + 1, j, pos, val);

    seg[idx].merge(seg[left], seg[right]);
}

long long query(int idx, int i, int j, int ini, int fim) {
    refresh(idx, i, j);

    if(i > j || j < ini || fim < i)
	return INF;

    if(ini <= i && j <= fim) 
	return seg[idx].Min;

    int mid = (i + j) >> 1;
    int left = idx << 1;
    int right = left | 1;

    return min(query(left, i, mid, ini, fim), query(right, mid + 1, j, ini, fim));
}

bool ok(int x) {
    build(1, 1, n);

    long long dp;
    for(int i = n - 1; i >= 1; --i) {
	update(1, 1, n, i + 1, min(n, i + x));
	dp = query(1, 1, n, i + 1, min(n, i + x)) + d[i];
	change(1, 1, n, i, dp);
    }

    return dp <= t;
}

long long solve() {
    int ini = 1;
    int fim = n - 1;

    while (ini < fim) {
	int mid = (ini + fim) >> 1;

	if(ok(mid))
	    fim = mid;
	else
	    ini = mid + 1;
    }
 
    long long menor = p[ini];

    for(int i = ini + 1; i <= n - 1; ++i)
	menor = min(menor, p[i]);

    return menor;
}

int main() {
    freopen("journey.in", "r", stdin);
    freopen("journey.out", "w", stdout);
    
    scanf("%d %d", &n, &t);

    for(int i = 1; i <= n - 1; ++i)
	scanf("%lld", &p[i]);

    for(int i = 2; i <= n - 1; ++i)
	scanf("%lld", &d[i]);

    printf("%lld\n", solve());

    return 0;
}	
