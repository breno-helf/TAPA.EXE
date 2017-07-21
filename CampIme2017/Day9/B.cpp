#include <bits/stdc++.h>
using namespace std;




int main () {
    int t;
    cin >> t;
    while (t--) {
	string s;
	cin >> s;
	int tam = s.size();
	if (tam == 1) cout << "YES" << '\n';
	else {
	    if (__builtin_popcount(tam) > 1) cout << "NO" << '\n';
	    else {
		bool ok = true;
		for (int i = 0; i < tam; i += 2) {
		    if (s[i] == 'A' && s[i + 1] == 'A') {
			ok = false;
		    }
		}
		
		if (ok) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	    }
	}
    }
    return 0;
}
