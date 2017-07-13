#include "bits/stdc++.h"
using namespace std;
int n;
long long len, a, b;
int solve(long long a, long long b, long long sum){
	vector<long long>ans;
	vector<long long>val;
	if(b <= len / 2){
		for(long long i = b; i >= a; --i)
			val.push_back(i);
	}
	else{
		long long cur = len - b + 1;
		long long add = 1;
		for(int i = b; i >= a; --i){
			val.push_back(cur);
			cur += add;
			if(cur == n + 1) cur = n - 1, add = -1;
		}
	}
	for(int i = b, p = 0; i >= a; --i, ++p){
		ans.push_back((val[p]+sum)%10);
		sum = (val[p]+sum) / 10;
	}
	reverse(ans.begin(),ans.end());
	for(auto i: ans) cout << i;
	cout << '\n';
}
int main(){
	cin >> n;	
	len = n + n - 1;
	cin >> a >> b;
	if(b > len / 2){
		if(len - b + 1 <= 10) solve(a,b,0);
		else{
			long long d = len - b + 1 - 11;
			solve(a,b,d/9+1);
		}
	}
	else{
		if(b <= 7) solve(a,b,0);
		else solve(a,b,(b-8)/9+1);
	}
	return 0;
}