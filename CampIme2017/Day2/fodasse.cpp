#include "bits/stdc++.h"
using namespace std;

const int maxn = 1e5 + 10;

int vec[maxn];

void gen(int n){
	for(int i = 1; i <= n; ++i)
		vec[i] = i;
	int cur = n;
	for(int i = n - 1; i >= 1; --i)
		vec[++cur] = i;
	vector<int>a;
	int soma=0;
	for(int i = n + n - 1; i >= 1; --i){
		a.push_back(soma);
		soma = (vec[i]+soma)/10;
	}
	reverse(a.begin(),a.end());
	cout << n << " " << a.size() << '\n';
	int len = a.size();
	for(int i = 0; i < len / 2; ++i) cout << a[i] << " ";
	cout << '\n';
	for(int i = len/2; i < a.size(); ++i) cout << a[i] << " ";
	cout << '\n';
	cout << '\n';
}

int main(){
	for(int i = 1; i <= 50; ++i)
		gen(i);
	return 0;
}