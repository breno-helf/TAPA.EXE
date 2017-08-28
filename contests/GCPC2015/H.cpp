#include<bits/stdc++.h>
using namespace std;

const int MAX = 1123;

#define pb push_back

int n;

map<string, int> M;
vector<int> adj[MAX];

vector<int> cm;
int mrk[MAX];
int id = 0;

void dfs(int u) {
    mrk[u] = 1;

    for (auto v : adj[u]) {
	if (!mrk[v]) dfs(v);
    }
}

int main() {
    cin >> n;
    
    for (int i = 0; i < n; i++) {
	string s;
	int k;
	cin >> s >> k;
	if (M.find(s) == M.end()) M[s] = id++;
	int st = -1;
	for (int j = 0; j < (int)s.size(); j++) {
	    if (s[j] == ':') st = j;
	}
	string r = "";
	for (int j = st; j < (int)s.size(); j++) {
	    r += s[j];
	}

	//cout << r << '\n';
	
	if (r == ":PROGRAM") cm.pb(M[s]);

	for (int j = 0; j < k; j++) {
	    cin >> r;
	    if (M.find(r) == M.end()) M[r] = id++;

	    adj[M[r]].pb(M[s]);
	}
    }
    
    for (auto u : cm) dfs(u);

    int resp = 0;

    //printf("--> %d\n", id);
    
    for (int i = 0; i < id; i++) if(mrk[i] == 0) resp++;

    cout << resp << '\n';    
}
