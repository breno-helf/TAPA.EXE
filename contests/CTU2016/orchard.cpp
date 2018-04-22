#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 1123;
const ll  INF = 0x3f3f3f3f3f3f3f3fLL;

struct Seg {
    int no[4 * MAX];

    Seg() {
        memset(no, 0, sizeof(no));
    }
    
    Seg(int sz) {
        for (int i = 0; i <= 4 * sz; i++) no[i] = 0;
    }
    
    void update(int id, int l, int r, int pos, int val) {
        if (l == r) {
            no[id] += val;
            return;
        }

        int L = 2 * id, R = 2 * id + 1;
        int mid = (l + r) / 2;
        if (pos <= mid) update(L, l, mid, pos, val);
        else update(R, mid + 1, r, pos, val);
        no[id] = no[L] + no[R];
    }

    int query(int id, int l, int r, int lo, int hi) {
        if (l >= lo && r <= hi) return no[id];
        if (r < lo || l > hi) return 0; 

        int L = 2 * id, R = 2 * id + 1;
        int mid = (l + r) / 2;
        return (query(L, l, mid, lo, hi) + query(R, mid + 1, r, lo, hi));
    }
}Kondo;

int n, m;
vector<pii> tree;
map<int, int> cmpY;
//vector<int> cmpY;

void rotate() {
    for (int i = 0; i < n; i++) {
        int x = tree[i].first;
        int y = tree[i].second;
        
        tree[i] = pii(y, m - x - 1);
    }
}

ll solve() {
    cmpY.clear();
    int N = n + 10;
    Kondo = Seg(N);
    
    for (int i = 0; i < n; i++) {
        int y = tree[i].second;
        cmpY[y] = 1;
        // cmpY.push_back(y);
    }
    sort(tree.begin(), tree.end());
    // sort(cmpY.begin(), cmpY.end());
    // cmpY.erase(unique(cmpY.begin(), cmpY.end()), cmpY.end());
    
    int cnt = 1;
    for (auto &e : cmpY) {
        e.second = cnt++;
    }
    
    ll ans = INF;
    for (pii P : tree) {
        int x = P.first, y = P.second;
        Kondo.update(1, 1, N, cmpY[y], 1);
        int rect = Kondo.query(1, 1, N, 1, cmpY[y]);
        if (2 * rect == n) {
            ans = min(ans, 1LL * (x + 1) * (y + 1));
        }
    }
    return ans;
}

int main() {
    while (scanf("%d%d", &m, &n) != EOF) {
        tree.clear();
        
        for (int i = 0; i < n; i++) {
            int x, y;
            scanf("%d%d", &x, &y);
            tree.push_back(pii(x, y));
        }

        if (n % 2 == 1) {
            puts("-1");
            continue;
        }
        
        ll ans = INF;
        for (int k = 0; k < 4; k++) {
            ans = min(ans, solve());
            rotate();
        }
        
        if (ans != INF) {
            printf("%lld\n", ans);
        } else puts("-1");
    }
    
    return 0;
}
