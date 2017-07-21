#include "bits/stdc++.h"
using namespace std;

const int maxn = 2e3 + 10;

int n, a[maxn];
multiset<int>s;

int get(int x){
	int ans = 1;
	vector<int>vec;
	int soma = 0;
	s.erase(s.find(x));
	while(!s.empty() && soma + *s.begin() <= x){
		soma += *s.begin();
		vec.push_back(*s.begin());
		s.erase(s.begin());
		++ans;
	}
	for(auto i: vec) s.insert(i);
	s.insert(x);
	return ans;
}

int solve(){
	int ans = 0;
	for(int i = 1; i <= n; ++i){
		ans = max(ans,get(a[i]));
	}
	return ans;
}

int main(){
	cin >> n;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		s.insert(a[i]);
	}
	cout << solve() << '\n';
	return 0;
}