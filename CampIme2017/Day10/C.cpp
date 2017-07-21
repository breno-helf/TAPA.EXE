#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
#define debug(args...) //fprintf(stderr,args)
typedef pair<int,int>pii;

const int maxn = 3e5 + 10;
const int block = 350;

int n, q;
vector<int>adj[maxn];

int ckey, cvalue;
map<string,int>key,value;
map<int,string>rvalue;

map<int,int>m[maxn];

int freq[maxn];
vector<int>nodes[maxn];
int ini[maxn], fim[maxn], h[maxn], t;

void dfs(int v){
	ini[v] = ++t;
	for(auto u: adj[v]){
		h[u] = h[v] + 1;
		dfs(u);
	}
	fim[v] = t;
}

int resp[block + 1][maxn];
map<int,int>save;
int cont;

void dfs0(int v, int key, int id, int last){
	int LAST = last;
	
	if(m[v].find(key) != m[v].end())
		LAST = v;

	if(LAST != -1){
		int u = LAST;
		resp[id][v] = m[u][key];
	}

	for(auto u: adj[v])
		dfs0(u,key,id,LAST);
}

void process(int id){
	++cont;
	save[id] = cont;
	dfs0(1,id,cont,-1);
}	

void precompute(){
	dfs(1);

	for(int i = 1; i <= ckey; ++i)
		if(freq[i] >= block)
			process(i);
}

int get(int v, int id){
	int ans = 0;
	if(freq[id] < block){
		int last = -1;
		for(auto u: nodes[id]){
			
			if(h[u] > h[v]) continue;
		
			if(!(ini[u] <= ini[v] && fim[v] <= fim[u])) continue;
	
			if(h[u] > last) last = h[u], ans = m[u][id];
		}
	} else {
		ans = resp[save[id]][v];
	}	
	return ans;
}

int main(){
	cin.sync_with_stdio(false);

	cin >> n;

	for(int v = 1; v <= n; ++v){
		int par, k;
		cin >> par >> k;

		adj[par].pb(v);

		while(k--){
			string s;
			cin >> s;
			string a, b;

			int pointer = 0;
			for(int i = 0; i < s.size(); ++i){
				if(s[i] == '='){
					pointer = i;
					break;
				}
				a.pb(s[i]);
			}	

			for(int i = pointer+1; i < s.size(); ++i)
				b.pb(s[i]);

			if(key.find(a) == key.end())
				key[a] = ++ckey;
				

			if(value.find(b) == value.end()){
				value[b] = ++cvalue;
				rvalue[cvalue] = b;
			}

			int KEY = key[a];
			int VALUE = value[b];

			m[v][KEY] = VALUE;
			++freq[KEY];
			nodes[KEY].pb(v);
		}
	}

	precompute();

	cin >> q;

	while(q--){
		int v;
		string s;
		cin >> v >> s;
		if(key.find(s) == key.end()) cout << "N/A\n";
		else{
			int KEY = key[s];
			int ans = get(v,KEY);
			if(!ans) cout << "N/A\n";
			else cout << rvalue[ans] << '\n';
		}	
	}

	return 0;
}