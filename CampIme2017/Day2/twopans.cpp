#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef pair<int, int> pii;

const int MAX = 2123;

int n;
queue<int> Q1, Q2;
vector<pii> ans, t;
int main () {
    scanf ("%d", &n);
    
    for (int i = 1; i <= n; i++) {
	Q1.push(i);
	Q2.push(i);
    }

    while (Q1.size() || Q2.size()) {
	if (Q1.size() >= 2) {
	    int a = Q1.front();
	    Q1.pop();
	    int b = Q1.front();
	    Q1.pop();
	    
	    ans.pb(pii(a, b));
	    t.pb(pii(1, 1));
	} else if ((int)Q1.size() == 1) {
	    int a = Q1.front();
	    Q1.pop();
	    int b = Q2.front();
	    Q2.pop();
	    if (a == b) {
		b = 0;
		Q2.push(a);
	    }
	    ans.pb(pii(a, b));
	    t.pb(pii(1, 2));
	} else {
	    int a = Q2.front();
	    Q2.pop();
	    int b;
	    if (Q2.empty()) {
		b = 0;
	    } else {
		b = Q2.front();
		Q2.pop();
	    }
	    ans.pb(pii(a, b));
	    t.pb(pii(2, 2));
	}
    }

    printf ("%d\n", (int)ans.size());
    
    for (int i = 0; i < (int)ans.size(); i++) {
	if (ans[i].second == 0) {
	    printf ("%d%c 0X\n", ans[i].first, (t[i].first == 1) ? 'A' : 'B'); 
	} else {
	    char a, b;
	    a = (t[i].first == 1) ? 'A' : 'B';
	    b = (t[i].second == 1) ? 'A' : 'B';

	    printf("%d%c %d%c\n", ans[i].first, a, ans[i].second, b);
	}	
    }

    return 0;
}

    
