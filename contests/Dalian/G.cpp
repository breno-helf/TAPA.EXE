#include "bits/stdc++.h"
using namespace std;

long long n, m;

int main() {
	while(cin >> n >> m) {
		long long x = n / 2;
		long long y = n - x;
		if(m >= x * y) cout << "T\n";
		else cout << "F\n";
	}

	return 0;
}