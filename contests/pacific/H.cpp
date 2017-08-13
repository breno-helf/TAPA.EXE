#include "bits/stdc++.h"
using namespace std;

typedef pair <long long, long long> pii;

const long long N = 1e18;

typedef struct node * pnode;

struct node
{
	long long ans;
	pnode L, R;

	node() {
		ans = 0;
		L = R = NULL;
	}
};

pnode seg = new node();

long long resp(pnode idx) {
	if(!idx)
		return 0LL;

	return idx->ans;
}

void update(pnode &idx, long long i, long long j, long long pos, long long val) {
	if(i == j) {
		idx->ans = max(idx->ans, val);
		return;
	}

	long long mid = (i + j) >> 1;

	if(pos <= mid) {
		if(!idx->L) 
			idx->L = new node();

		update(idx->L, i, mid, pos, val);
	}  
	else {
		if(!idx->R)
			idx->R = new node();

		update(idx->R, mid + 1, j, pos, val);
	}

	idx->ans = max(resp(idx->L), resp(idx->R));
}

long long get(pnode idx, long long i, long long j, long long ini, long long fim) {
	if(i > j || j < ini || fim < i || !idx)
		return 0LL;

	if(ini <= i && j <= fim)
		return idx->ans;

	long long mid = (i + j) >> 1;

	return max(get(idx->L, i, mid, ini, fim), get(idx->R, mid + 1, j, ini, fim));
}

long long len;
int n;

vector <pii> vec;

long long solve() {
	sort(vec.begin(), vec.end());
	reverse(vec.begin(), vec.end());

	long long ans = 0LL;

	for(int i = 0; i < n; ++i) {
		long long l = vec[i].first;
		long long r = vec[i].second;

		long long dp = (r - l + 1) + get(seg, 1, N, r + 1, N);
		update(seg, 1, N, l, dp);
		ans = max(ans, dp);
	}

	return ans;
}

int main() {
	cin >> len >> n;

	for(int i = 0; i < n; ++i) {
		long long l, r;
		cin >> l >> r;
		vec.push_back({l, r});
	}

	cout << len - solve() << '\n';

	return 0;
}
