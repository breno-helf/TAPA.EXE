//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 212345;
const ll  INF = ((ll)1e18 + 2LL);
const ll  MOD = 1000000007;

int n, q;
ll a[MAX];
ll seg[4 * MAX];

void build(int id, int l, int r) {
    if (l == r) {
        seg[id] = a[l];
        return;
    }
    
    int mid = (l + r) >> 1;
    int esq = id << 1;
    int dir = esq | 1;

    build(esq, l, mid);
    build(dir, mid + 1, r);
    seg[id] = min(seg[esq], seg[dir]);
}

int query(int idx, int i, int j, int ini, int fim, ll val) {
    if(i > j || j < ini || fim < i)
        return -1;

    if(seg[idx] > val)
        return -1;

    if(i == j)
        return i;

    int mid = (i + j) >> 1;
    int left = idx << 1;
    int right = left | 1;

    int ret = query(left, i, mid, ini, fim, val);

    if(ret != -1)
        return ret;

    return query(right, mid + 1, j, ini, fim, val);
}

inline int search(ll val, int L, int R) {
    int q = query(1, 1, n, L, R, val);
    if(q == -1) 
        q = R;
    return q;
}

inline ll solve(ll val, int L, int R) {
    while (L <= R) {
        L = search(val, L, R);
        val = val % a[L++];
    }
    return val;
}

int main() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
        scanf("%lld\n", &a[i]);
    
    build(1, 1, n);

    for (int k = 1; k <= q; k++) {
        ll v;
        int l, r;

        scanf("%lld %d %d", &v, &l, &r);
        printf("%lld\n", solve(v, l, r));
    }

    return 0;
}
