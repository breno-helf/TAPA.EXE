#include <bits/stdc++.h>
using namespace std;

#define pb push_back

vector<int> h, w;

int main () {
    int t;
    cin >> t;
    while (t--) {
	w.clear();
	h.clear();
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
	    int a;
	    cin >> a;
	    w.pb(a);
	}
	
	for (int i = 0; i < n; i++) {
	    int a;
	    cin >> a;
	    h.pb(a);
	}

	int me, mx = -1;

	sort(h.begin(), h.end());
	//printf ("Oi %d\n", h.back());
	me = h.back() * w[0];
	
	h.pop_back();
	//printf ("Tchau\n");
	swap(w[0], w[(int)w.size() - 1]);
	w.pop_back();
	sort(w.begin(), w.end());

	int j = n - 2;
	
	for (int i = 0; i < (n - 1); i++) {
	    //printf ("%d %d\n", i, j);
	    //printf ("--> %d\n", w[j] * h[i]);
	    mx = max(mx, w[j] * h[i]);
	    j--;	    
	}

	if (me > mx) {
	    cout << "YES" << '\n';
	} else cout << "NO" << '\n';
    }
}
