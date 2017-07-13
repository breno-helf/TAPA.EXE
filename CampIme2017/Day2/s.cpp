#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 10;
const ll mod = 1e9 + 7;

int n;

ll val[maxn];

int main(){
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> val[i];
	ll soma = 0;
	ll p = 1;
	for(int i = 1; i <= n - 1; ++i)
		p = (p * 2) % mod;
	p = (p - 1 + mod) % mod;
	for(int i = 1; i <= n; ++i)
		soma = (soma + p * val[i]) % mod;
	cout << soma << '\n';
	return 0;
}