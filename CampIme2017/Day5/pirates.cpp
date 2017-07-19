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

ll n;
vector<ll> primes;
vector<ll> fac;
priority_queue<pll> Q;
int crivo[MAX];
pll last;

map<ll, map<ll, int> > M;

ll calc (ll X) {
    ll ret = 1;
    for (auto e : M[X]) {
	ret *= (e.second + 1);
    }
    return ret;
}

double LG (map<ll, int> F) {
    double ret = 1;
    for (auto e : F) {
	for (int i = 0; i < e.second; i++) {
	    ret *= (double)log10((double)e.first);
	}
    }
    return ret;
}

void p (ll X) {
    for (auto e : M[X]) {
	cout << e.second << ' ';
    }
    cout << '\n';
}

int main () {
    cin >> n;
    for (int i = 2; i * i <= (int)1e8; i++) {
	if (!crivo[i]) {
	    primes.pb(i);
	    for (int k = i * i; k < MAX; k += i)
		crivo[k] = i;
	}
    }
    for (int i = 0; i < 15; i++) {
	Q.push(pll(-primes[i], 1));
    }
    map<ll, int> F;
    F[2] = 1;
    M[2] = F;
    last = pll(1, 0);
    int it = 0;
    while (!Q.empty()) {
	it++;
	pll u = Q.top();
	Q.pop();
	ll num = -u.first, qtd = u.second;
	if (num <= last.first) continue;
	if (qtd <= last.second) continue;
	//cout << num << " --> " << calc(num) << '\n';
	fac.pb(num);
	F.clear();
	for (int i = 0; i < 12; i++) {
	    F = M[num];
	    F[primes[i]]++;
	    
	    if (num > (ll)(4e18 + 100) / (ll)primes[i])
		continue;
	    
	    ll at = num * primes[i];
	    //cout << at << '\n';
	    if (M.find(at) == M.end()) M[at] = F;
	    Q.push(pll(-at, calc(at)));
	}
	last = pll(num, qtd);
    }
    sort(fac.begin(), fac.end());

    // for (int i = 0; i < (int)fac.size(); i++) {
    // 	cout << (i + 1) << ' ' << fac[i] << '\n';
    // }
    
    for (int i = 0; i < (int)fac.size(); i++) {
	if (fac[i] > n) {
	    cout << fac[i] << '\n';
	    break;
	}
    }
}

