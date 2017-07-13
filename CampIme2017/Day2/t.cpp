#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define REP(i,a,b) for(int i = a; i >= b; --i)
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
#define debug(args...) fprintf(stderr,args)


int t, n;
string s;

int cnt[20];

bool ok(int fim){
	FOR(d,0,9) cnt[d] = 2;
	FOR(i,0,fim) --cnt[s[i] - '0'];
	FOR(d,0,9) if(cnt[d] < 0) return false;
	return true;
}

char acha(int start){
	REP(d,start-1,0) 
		if(cnt[d]){
			--cnt[d];
			return (char)(d+'0');
		}
	return -1;
}

string pre(int fim){
	string ret;
	FOR(i,0,fim) ret.pb(s[i]);
	return ret;
}

string solve(int l, int r){
	string ret = pre(l-1);
	FOR(i,l,r){
		char c;
		if(i == l) c = acha(s[l]-'0');
		else c = acha(10);
		if(c == -1) return ret;
		ret.pb(c);
	}
	return ret;
}

string fodasse(int len){
	FOR(d,0,9) cnt[d] = 2;
	string ret;
	while(len--){
		char c = acha(10);
		if(c == -1) break;
		ret.pb(c);
	}
	return ret;
}

void maior(string &ans, string cmp){
	if(ans.size() > cmp.size()) return;
	if(cmp.size() > ans.size()) ans = cmp;
	else{
		int n = (int)ans.size();
		FOR(i,0,n-1)
			if(ans[i] < cmp[i]){
				ans = cmp;
				return;
			}
			else if(ans[i] > cmp[i]) return;
	}
}

int main(){
	cin >> t;
	while(t--){
		cin >> s;
		string ans;
		ans = "0";
		n = (int)s.size();
		maior(ans,fodasse(n-1));
		for(int i = 0; i < n; ++i)
			if(ok(i)){
				maior(ans,pre(i));
				if(i+1 < n) maior(ans,solve(i+1,n-1));
			}
			else break;
		cout << ans << '\n';
	}
	return 0;
}