#include <bits/stdc++.h>

using namespace std;

typedef pair<long long, long long> pii;

const int INF = 0x3f3f3f3f;

struct Circle{
    long long x, y, r;
    int id;
    Circle() {
	x = 0, y = 0;
    }
    Circle(long long a, long long b,int c) : x(a), y(b), r(b), id(c) {}
};

Circle c[212345];
int qc;


int main() {
    int n;
    scanf("%d", &n);

    int d = 250;

    set <pii> st;
    qc = 0;
    for (int i = 0; i < n; ++i) {
	int t;
	long long x, y;
	scanf("%d%lld%lld", &t, &x, &y);

	if(t == 1){
	    c[qc++] = Circle(x, y, i + 1);
	    st.insert(pii(x, qc - 1));
	}
	else {
	    int find = -1;
	    int tot = d;
	    vector <long long> v;
	    set<pii>::iterator it = st.lower_bound(pii(x, -INF));
	    if (!st.empty()) {
		while(tot > 0){
		    if (it != st.end()) 
			v.push_back(it->second);
		    if(it == st.begin()) break;
		    it--;
		    tot--;
		}
		tot = d;
		it = st.lower_bound(pii(x,-INF));
		while(tot > 0) {
		    if(it == st.end()) break;
		    v.push_back(it->second);
		    it++;
		    tot--;
		}
		for (int j = 0; j < (int)v.size(); ++j) {
		    long long dx = x - c[v[j]].x;
		    long long dy = y - c[v[j]].y;
		    long long r = c[v[j]].y;
		    if(dx*dx + dy*dy < r*r) {
			find = c[v[j]].id;
			it = st.lower_bound(pii(c[v[j]].x,-INF));
			if (it != st.end()) st.erase(it);
			break;
		    }
		}
	    }
	    printf("%d\n", find);
	}
    }

}
