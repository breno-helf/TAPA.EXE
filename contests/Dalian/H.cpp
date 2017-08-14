//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 112345;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n, a[MAX];
int m;
int seg[4 * MAX];

void build(int id, int l, int r) {
    if (l == r) {
	seg[id] = a[l];
	return;
    }

    int mid = (l + r) / 2;
    int esq = 2 * id;
    int dir = esq + 1;

    build(esq, l, mid);
    build(dir, mid + 1, r);

    seg[id] = min(seg[esq], seg[dir]);
}

int query(int id, int l, int r, int lo, int hi, int val) {
    if (l > r || r < lo || l > hi)
	return -1;

    if (seg[id] > val)
	return -1;

    if (l == r) return l;
    
    int mid = (l + r) / 2;

    int Q = query(2 * id, l, mid, lo, hi, val);

    if (Q != -1)
	return Q;
    
    return query(2 * id + 1, mid + 1, r, lo, hi, val);
}


int search(int cur, int l, int r) {
    int ret = query(1, 1, n, l, r, cur);
    if (ret == -1) return r;
    return ret;
}

int solve(int l, int r) {
    int cur = a[l];
    l++;
    while(l <= r) {
	l = search(cur, l, r);
	cur = cur % a[l++];
    }
    return cur;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	    scanf("%d", a + i);
	
	build(1, 1, n);
	
	scanf("%d", &m);
	for (int k = 1; k <= m; k++) {
	    int l, r;
	    scanf("%d %d", &l, &r);
	    printf("%d\n", solve(l, r));
	}
    }
    return 0;
}

