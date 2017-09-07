#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef pair<int, int> pii;

map<string, vector<pii> > M;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
	M.clear();
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
	    string s, r;
	    int L, R, V;
	    cin >> s >> L >> R >> V;
	    
	    for (int k = 0; k < V; k++) {
		cin >> r;
		M[r].pb(pii(L, -1));
		M[r].pb(pii(R, 1));
	    }
	}

	vector<string> resp;
	
	for (auto m : M) {  
	    int cur = 0;
	    bool ok = true;
	    sort(m.second.begin(), m.second.end());
	    for (auto e : m.second) {
		cur += e.second;
		if (cur > 1 || cur < -1) ok = false;
	    }
	    if (!ok) resp.pb(m.first);
	}

	cout << resp.size() << '\n';
	for (string s : resp) {
	    cout << s << '\n';
	}
    }

    return 0;
}
