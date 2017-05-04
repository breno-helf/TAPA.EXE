#include <cstdio>
#include <vector>

using namespace std;

const int N = 100100;

vector <int> adj[N];
vector <int> ans;

pair<int,int> t[8*N];
int lazy[8*N];


pair<int,int> merge(pair<int,int> a, pair<int,int> b){
	if(a.second == b.second){
		if(a.first > b.first){
			return a;
		}
		else return b;
	}
	else if(a.second < b.second){
		return a;
	}
	else{
		return b;
	}
}
void push(int idx, int l, int r){
	int esq = idx*2+1, dir = idx*2+2;
	if(l!=r){
		lazy[esq]+=lazy[idx];
		t[esq].second+=lazy[idx];
		lazy[dir]+=lazy[idx];
		t[dir].second+=lazy[idx];
	}
	lazy[idx]=0;
}

void build(int idx, int l, int r){
	if(l==r){
		t[idx]=make_pair(l,l);
		lazy[idx]=0;
		return;
	}
	int m = (l+r)/2;
	int esq = 2*idx+1, dir = 2*idx+2;
	build(esq, l, m);
	build(dir, m+1, r);
	lazy[idx]=0;
	t[idx]=merge(t[esq],t[dir]);
}

void add(int idx, int l, int r, int s, int e, int val){
	if(s>e){
		return;
	}
	if(l == s && r == e){
		t[idx].second+=val;
		lazy[idx]+=val;
		return;
	}
	push(idx,l,r);
	int m = (l+r)/2, esq = 2*idx+1, dir = 2*idx+2;
	add(esq, l, m, s, min(m,e),val);
	add(dir, m+1, r, max(m+1,s), e, val);
	t[idx]=merge(t[esq],t[dir]);	
}

int main(){
	int test;
	scanf("%d", &test);

	for(int cas = 0; cas < test; cas++){
		int n, m;
		scanf("%d%d", &n, &m);

		ans.clear();
		build(0,0,n-1);
		for(int i = 0; i < n; i++){
			adj[i].clear();
		}
		for(int i = 0; i < m; i++){
			int a, b;
			scanf("%d%d", &a, &b);
			a--,b--;
			adj[a].push_back(b);
			add(0,0,n-1,b,b,-1);
		}
		for(int i = 0; i < n; i++){
			int v = t[0].first;
			add(0,0,n-1,v,v,10000000);
			ans.push_back(v+1);
			add(0,0,n-1,v+1,n-1,-1);
			for (int j=0;j<adj[v].size();j++)
			{
				int nxt=adj[v][j];
				add(0,0,n-1,nxt,nxt,1);
			}
		}
		for(int i = 0; i < ans.size(); i++){
			if(i)printf(" ");
			printf("%d",ans[i]);
		}
		printf("\n");


	}

}
