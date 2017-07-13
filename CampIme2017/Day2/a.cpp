#include "bits/stdc++.h"
using namespace std;

int t, n, s;

long long solve(vector<long long>vec){
	if(vec.size() < s) return 0;
	sort(vec.begin(),vec.end());
	long long ans = vec[0];
	for(int i = 0; i < s; ++i) vec[i] -= ans;
	reverse(vec.begin(),vec.end());
	vec.pop_back();
	return ans + solve(vec);
}

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&s);
		vector<long long>vec;
		for(int i = 0; i < n; ++i){
			long long p;
			scanf("%lld",&p);
			vec.push_back(p);
		}
		printf("%lld\n",solve(vec));
	}
	return 0;
}