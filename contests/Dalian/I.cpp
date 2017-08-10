#include "bits/stdc++.h"
using namespace std;

typedef pair <int, int> pii;
const int maxn = 2e5 + 10;

int t, n, m;

pii e(int a, int b) {
	return pii(min(a, b), max(a, b));
}

set <pii> edges;

int dis[maxn];
set <int> List;
set <int> :: iterator it;

bool check(int a, int b){
	return edges.find(e(a, b)) == edges.end();
}

void bfs(int source) {
	for(int i = 0; i < n; ++i) {
		dis[i] = -1;

		if(i != source) 
			List.insert(i);
	}

	dis[source] = 0;
	queue <int> Q;

	Q.push(source);

	while(!Q.empty()) {
		int v = Q.front();
		Q.pop();

		vector <int> del;

		for(it = List.begin(); it != List.end(); ++it) {
			int u = (*it);

			if(check(u, v))
				del.push_back(u);
		}

		for(int i = 0; i < del.size(); ++i) {
			int u = del[i];

			dis[u] = dis[v] + 1;
			Q.push(u);

			List.erase(u);
		}
	}	
}

int main() {
	scanf("%d", &t);

	while(t--) {
		scanf("%d %d", &n, &m);

		edges.clear();

		for(int i = 0; i < m; ++i) {
			int a, b;
			scanf("%d %d", &a, &b);

			--a, --b;

			edges.insert(e(a, b));
		}

		int source;
		scanf("%d", &source);

		--source;

		bfs(source);

		bool start = false;
		
		for(int i = 0; i < n; ++i)
			if(i != source) {
				if(start) printf(" ");
				else start = true;

				printf("%d", dis[i]);
			}

		printf("\n");
	}
}