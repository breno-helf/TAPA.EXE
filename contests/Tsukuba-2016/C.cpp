//If you are trying to hack me I wish you can get it, Good Luck :D
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 212345;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n, m;
pii pro[MAX];
int lo[MAX], hi[MAX];

int main () {
    for (int i = 0; i < MAX; i++)
	lo[i] = hi[i] = 1;

    scanf ("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
	int x, id;
	scanf ("%d %d", &x, &id);
	pro[i] = mp(x, id);
    }
    sort(pro, pro + m);

    for (int i = 0; i < m; i++) {
	hi[pro[i].second + 1] = max(hi[pro[i].second + 1], hi[pro[i].second] + 1);
	lo[pro[i].second] = max(lo[pro[i].second], lo[pro[i].second + 1] + 1);
    }
    
    for (int i = 1; i <= n; i++)
	printf("%d ", lo[i] + hi[i] - 1);
    printf("\n");
}

