#include <bits/stdc++.h>

using namespace std;


const int N = 100100;

int vec[N];
multiset <int> st;

int main(){
	//freopen()
	int n, k, r;
	scanf("%d%d%d", &n, &k, &r);
	for(int i = 0; i < k; i++){
		scanf("%d", &vec[i]);
	}

	sort(vec,vec+k);
	int j = 0;
	int ans = 0;
	for(int i = 1; i <= n-r+1; i++){
		while(!st.empty() && *st.begin() < i){
			st.erase(st.begin());
		}
		while(vec[j] < i+r && j < k){
			st.insert(vec[j]);
			j++;
		}
		//printf("%d %d\n",i, st.size());
		for(auto z:st){
			//printf("%d\n",z);
		}
		while(st.size()<2){
			ans++;
			if(st.find(i+r-1)==st.end())st.insert(i+r-1);
			else st.insert(i+r-2);
		}
	}
	printf("%d\n", ans);

}
