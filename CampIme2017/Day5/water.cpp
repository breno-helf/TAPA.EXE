#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define FOR(i,a,b) for(int i = a; i <= b; ++i)

const int maxn = 30 + 10;

int n, k;
char s[maxn][maxn];

typedef pair<int,int>pii;

int dx[] = {+1, +1, +1};
int dy[] = {-1, 0, +1};

int di[] = {1, 0, -1, 0, 1, 1, -1, -1};
int dj[] = {0, 1, 0, -1, 1, -1, 1, -1};

int mrk[maxn][maxn];

vector<pii> CMP;

bool ok(int i, int j){
    for(int c = 0; c < 3; ++c){
	int x = dx[c] + i;
	int y = dy[c] + j;
	if(x < 0 || y < 0 || y >= n || x >= n) return false;
	if(s[x][y] == '.') return false;
    }
    return true;
}

void process(){
    for (auto u : CMP) {
	int i = u.first;
	int j = u.second;
	if(s[i][j] == '.' && ok(i,j)){
	    s[i][j] = '*';
	    return;
	}
    }
}

void build() {
    queue<pii> Q;
    for (int i = 1; i < (n - 1); i++) {
	Q.push(pii(0, i));
    }
    
    while(!Q.empty()) {
	pii u = Q.front();
	int i = u.first;
	int j = u.second;

	CMP.push_back(u);
	
	for (int a = 0; a < 8; a++) {
	    int x = i + di[a];
	    int y = j + dj[a];

	    if (x < 0 || x >= n || y < 0 || y >= n) continue;
	    if (!mrk[x][y] && s[x][y] != '#') {
		mrk[x][y] = 1;
		Q.push(pii(x, y));
	    }
	}
	Q.pop();
    }
}

void solve(){
    build();
    while(k){
	process();
	--k;
    }
}

int main(){
    scanf("%d",&n);
    for(int i = 0; i < n; ++i)
	scanf(" %s",s[i]);
    scanf("%d",&k);
    solve();
    FOR(i,0,n-1)
	printf("%s\n",s[i]);
    return 0;
}
