#include "bits/stdc++.h"
using namespace std;

int t, n, k;
string s;

int main(){
	cin >> t;
	while(t--){
		cin >> n >> k >> s;
		vector<int>vec;
		int maior = INT_MIN;
		int ans = 0;
		for(int i = 0; i < n; ++i){
			int j = i;
			int sz = 0;
			while(j < n && s[i] == s[j]){
				++sz;
				++j;
			}	
			ans += sz / k;
			if(sz % k) ++ans;
			vec.push_back(sz);
			maior = max(maior,sz);
			i = j - 1;
		}
		if(maior < k) cout << "-1\n";
		else cout << ans << '\n';
	}
	return 0;
}