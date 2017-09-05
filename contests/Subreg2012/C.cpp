#include<bits/stdc++.h>
using namespace std;

const int MAX = 11234;

typedef long long ll;

int n;
ll a[MAX];
ll sum = 0, par = 0;


int main() {
    while(scanf("%d", &n) != EOF) {
	multiset<ll> M;
	sum = 0;
	par = 0;
	for (int i = 0; i < n; i++) {
	    scanf("%lld", a + i);
	    M.insert(a[i]);
	    sum += a[i];
	    if (i % 2 == 0) par += a[i];
	}
	int i = 0, j = n - 1;
	int st = 0;
	ll resp = 0;
	for (int x = 0; x < n; x++) {
	    //printf("%lld -- %lld\n", par, sum - par);
	    if (x % 2 == 0) {
		if (M.upper_bound(a[i]) == M.end() && M.count(a[i]) == 1) {
		    if (i % 2 == 0) {
			par -= a[i];
			sum -= a[i];
			resp += a[i];
			M.erase(M.find(a[i]));
			st = 1;
			i++;
		    } else {
			sum -= a[i];
			resp += a[i];
			M.erase(M.find(a[i]));
			st = 0;
			i++;
		    }
		    continue;
		} else if (M.upper_bound(a[j]) == M.end() && M.count(a[j]) == 1) {
		    if (j % 2 == 0) {
			par -= a[j];
			sum -= a[j];
			resp += a[j];
			M.erase(M.find(a[j]));
			j--;
			st = 1;
		    } else {
			sum -= a[j];
			M.erase(M.find(a[j]));
			resp += a[j];
			j--;
			st = 0;
		    }
		    continue;
		}
		
		ll impar = sum - par;
		if (par > impar) {
		    if (i % 2 == 0) {
			par -= a[i];
			sum -= a[i];
			resp += a[i];
			M.erase(M.find(a[i]));
			st = 1;
			i++;
		    }
		    else {
			par -= a[j];
			sum -= a[j];
			resp += a[j];
			M.erase(M.find(a[j]));
			
			j--;
			st = 1;
		    }		    
		} else {
		    if (i % 2 == 1) {
			sum -= a[i];
			resp += a[i];
			M.erase(M.find(a[i]));
			st = 0;
			i++;
		    }
		    else {
			sum -= a[j];
			M.erase(M.find(a[j]));
			resp += a[j];
			j--;
			st = 0;
		    }		    
		}		
	    } else {
		if (a[i] > a[j]) {
		    M.erase(M.find(a[i]));
		    sum -= a[i];
		    if (st == 0) par -= a[i];
		    i++;
		} else {
		    M.erase(M.find(a[j]));
		    sum -= a[j];
		    if (st == 0) par -= a[j];
		    j--;
		}
	    }
	}
	printf("%lld\n", resp);
    }
}
