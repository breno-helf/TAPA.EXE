#include <bits/stdc++.h>
using namespace std;


#define pb push_back

vector<int> v;
vector<int> q;
vector< vector<int> > magic;

bool is_magic (vector<int> u) {
    int k = u[0] + u[1] + u[2];
    for (int i = 0; i < 3; i++) {
	int cur = 0;
	for (int j = 0; j < 3; j++) {
	    cur += u[i * 3 + j];
	}
	if (cur != k) return false;
    }
    for (int i = 0; i < 3; i++) {
	int cur = 0;
	for (int j = 0; j < 3; j++) {
	    cur += u[i + 3 * j];
	}
	if (cur != k) return false;
    }
    int cur = u[0] + u[4] + u[8];
    if (cur != k) return false;
    cur = u[2] + u[4] + u[6];
    if (cur != k) return false;
    return true;
}

int distance (vector<int> u, vector<int> w) {
    int ret = 0;
    for (int i = 0; i < 9; i++) {
	ret += abs(u[i] - w[i]);
    }
    return ret;
}

int main () {
    for (int i = 1; i <= 9; i++) {
	int x;
	scanf ("%d", &x);
	v.pb(x);
	q.pb(i);
    }
    
    do {
	if (is_magic(q)) magic.pb(q);
    } while (next_permutation(q.begin(), q.end()));

    int resp = 100000;
    
    for (vector<int> u : magic) {
	// for (int i = 0; i < 9; i++)
	//     printf ("%d ", u[i]);
	// printf ("\n");	
	resp = min(resp, distance(u, v));
    }

    printf ("%d\n", resp);
}
