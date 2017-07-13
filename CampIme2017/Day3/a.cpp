#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
#define REP(i,a,b) for(int i = a; i >= b; --i)
#define debug(args...) //fprintf(stderr,args)

const int maxn = 3e5 + 10;

typedef pair<int,int>pii;
typedef long long ll;

int n, q;
vector<pii>P;

int x, y;

set<int>ps,rs;
set<int>::iterator it;
map<int,int>pm,rm;

int ans[maxn];

int w(int id){
	if(id < 0) return 0;
	return ans[id];
}

void compress(){
	for(auto i: P){
		ps.insert(i.first); 
		rs.insert(i.second);
	}
	for(auto i: rs) rm[i] = ++y;

	ps.insert(INT_MIN);
	rs.insert(INT_MIN);
	ps.insert(INT_MAX);
	rs.insert(INT_MAX);

}

typedef struct node * pnode;

struct node{
	int sum;
	pnode L, R;
	node(){
		L = R = NULL;
		sum = 0;
	}
};

int no;
pnode root[maxn];
map<int,int>raiz;

int soma(pnode &idx){
	if(!idx) return 0;
	return idx->sum;
}

pnode build(int i, int j){
	pnode cur = new node();
	if(i == j) return cur;
	int mid = (i + j) >> 1;
	cur->L = build(i,mid);
	cur->R = build(mid+1,j);
	return cur;
}

pnode update(pnode cur, int i, int j, int pos){
	pnode idx = new node();
	idx->sum = cur->sum;
	idx->L = cur->L;
	idx->R = cur->R;
	if(i == j){
		++idx->sum;	
		return idx;
	}
	int mid = (i+j) >> 1;
	if(pos <= mid) idx->L = update(idx->L,i,mid,pos);
	else idx->R = update(idx->R,mid+1,j,pos);
	idx->sum = soma(idx->L) + soma(idx->R);
	return idx;
}

int query(pnode idx, int i, int j, int ini, int fim){
	if(i > j || j < ini || fim < i) return 0;
	if(ini <= i && j <= fim) return idx->sum;
	int mid = (i + j) >> 1;
	return query(idx->L,i,mid,ini,fim) + query(idx->R,mid+1,j,ini,fim);
}

set<int> E;

void compute(){
	sort(P.begin(),P.end());
	root[0] = build(1,y);
	for(int i = 0; i < n; ++i){
		int j = i;
		while(j < n && P[i].first == P[j].first){
		    //int p = P[j].first;
			int r = P[j].second;
			++no;
			root[no] = update(root[no-1],1,y,rm[r]);
			++j;
		}
		// printf ("Raiz %d eh %d\n", P[i].first, no);
		raiz[P[i].first] = no;
		E.insert(no);
		i = j - 1;
	}
}

int get(int a, int b, int c, int d){

	if(a > b) swap(a,b);
	if(c > d) swap(c,d);
	int l, r, L, R;

	it = ps.lower_bound(a);
	l = (*it);

	it = --ps.upper_bound(b);
	r = (*it);

	it = rs.lower_bound(c);
	L = (*it);

	it = --rs.upper_bound(d);
	R = (*it);

	if(l > r || L > R) return 0;

	L = rm[L];
	R = rm[R];
	// printf ("== %d %d\n", l, r);
	l = raiz[l];
	r = raiz[r];
	
	//assert(L && l && r && R);
	int T = l;
	auto I = E.lower_bound(T);
	if (I == E.begin()) T = 0;
	else T = *(prev(I));
	// printf ("--> %d %d %d %d\n", L, R, r, l);
	// printf ("--> %d\n", query(root[l], 1, y, L, R));
	return query(root[r],1,y,L,R) - query(root[T],1,y,L,R);
}

int main(){
	scanf("%d",&n);
	FOR(i,1,n){
		int p, r;
		scanf("%d%d",&p,&r);
		P.pb(pii(p,r));
	}
	compress();
	compute();
	scanf("%d",&q);
	FOR(i,0,q-1){
		int e, f, g, h;
		scanf("%d%d%d%d",&e,&f,&g,&h);
		ll a, b, c, d;
		a = e ^ w(i-4);
		b = f ^ w(i-3);
		c = g ^ w(i-2);
		d = h ^ w(i-1);
		ans[i] = get(a,b,c,d);
		printf("%d\n",ans[i]);
	}
	return 0;
}
