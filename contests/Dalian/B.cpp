//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 1123456;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n, q;
int a[MAX];
vector<pii> C[MAX];
int ans[MAX];
int seen[MAX];
int bit[MAX];

struct que {
    int l, r, id;
    que(int L = 0, int R = 0, int ID = 0): l(L), r(R), id(ID) {}
    bool operator < (const que ot) const {
	return (r < ot.r);
    }
};

void update(int x, int val) {
    for (; x < MAX; x += x&-x)
	bit[x] += val;
}

int query(int x) {
    int ret = 0;
    for (; x > 0; x -= x&-x)
	ret += bit[x];
    return ret;
}

que Q[MAX];

int main() {
    while (scanf("%d%d", &n, &q) != EOF) {
	for (int i = 1; i <= n; i++) {
	    scanf("%d", a + i);
	    C[i].clear();
	}
	for (int i = 1; i <= n; i++) {
	    int r = i;
	    int cur = a[i];
	    for (pii e : C[i - 1]) {
		int l = __gcd(a[i], e.second);
		if (cur != l) {
		    C[i].pb(pii(r, cur));
		    cur = l;
		    r = e.first;
		}
	    }
	    C[i].pb(pii(r, cur));
	}

	
	for (int i = 1; i <= q; i++) {
	    int l, r;
	    scanf("%d%d", &l, &r);
	    Q[i] = que(l, r, i);
	}

	
	int k = 1;
	sort(Q + 1, Q + 1 + q);
	memset(seen, 0, sizeof(seen));
	memset(bit, 0, sizeof(bit));
	for (int i = 1; i <= n; i++) {
	    for (pii e : C[i]) {
		if (seen[e.second])
		    update(seen[e.second], -1);
		seen[e.second] = e.first;
		update(e.first, 1);
	    }
	    
	    while (Q[k].r == i) {
		ans[Q[k].id] = query(i) - query(Q[k].l - 1);
		k++;
	    }
	}

	for (int i = 1; i <= q; i++)
	    printf("%d\n", ans[i]);
    }
}

