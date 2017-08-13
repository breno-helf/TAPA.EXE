#include "bits/stdc++.h"
using namespace std;

#define debug(args...) fprintf(stderr, args)

typedef pair <int, int> pii;

struct st {
	long long mod;
	int id;
};

bool operator < (st a, st b) {
	return (a.mod < b.mod) || (a.mod == b.mod && a.id < b.id);
}

set <st> Set;
set <st> :: iterator it;

int n, k;

map <int, long long> cost;
vector <int> Left, Right;

long long ans;

void solve() {
	sort(Left.begin(), Left.end());
	Left.erase(unique(Left.begin(), Left.end()), Left.end());

	sort(Right.begin(), Right.end());
	Right.erase(unique(Right.begin(), Right.end()), Right.end());

	long long bonus;

	bonus = 0;
	for(int i = 0; i < Left.size(); ++i) {
		int x = Left[i];

		long long idas = cost[x] / k;
		long long mod = cost[x] % k;

		if(mod) {
			if(bonus >= mod) 
				bonus -= mod;
			else 
				++idas;
		}

		if(idas >= bonus / k) {
			idas -= (bonus / k);
			bonus = bonus % k;
		} 
		else {
			bonus -= idas * k;
			idas = 0;
		}

		ans += 2LL * idas * (long long)(-x);
		bonus += max(0LL, idas * k - cost[x]);
	}

	bonus = 0;
	reverse(Right.begin(), Right.end());

	for(int i = 0; i < Right.size(); ++i) {
		int x = Right[i];

		long long idas = cost[x] / k;
		long long mod = cost[x] % k;

		if(mod) {
			if(bonus >= mod) 
				bonus -= mod;
			else 
				++idas;
		}

		if(idas >= bonus / k) {
			idas -= (bonus / k);
			bonus = bonus % k;
		} 
		else {
			bonus -= idas * k;
			idas = 0;
		}

		ans += 2LL * idas * (long long)(x);
		bonus += max(0LL, idas * k - cost[x]);
	}
}

int main() {
	cin >> n >> k;

	for(int i = 0; i < n; ++i) {
		int x, m;
		cin >> x >> m;

		if(x < 0) {
			cost[x] += m;
			Left.push_back(x);
		}
		else 
			if(x > 0) {
				cost[x] += m;
				Right.push_back(x);
			}
	}

	solve();

	cout << ans << '\n';

	return 0;
}

