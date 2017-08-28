#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool is_prime(ll x) {
    if (x == 1LL || x == 0LL) return false;
    for (ll i = 2; i * i <= x; i++) {
	if (x % i == 0) return false;
    }
    return true;
}

int main(){
    string s;
    cin >> s;


    string r = "";
    int n = s.size();
    int ok = 1;
    for(int i = n-1; i >= 0; i--){
	if(s[i]=='3'||s[i]=='4'||s[i]=='7'){
	    ok = 0;
	}
		
	else if(s[i] == '6'){
	    r+='9';
	}
	else if(s[i] == '9'){
	    r+='6';
	}
	else{
	    r+=s[i];
	}
    }
	
    if (!ok) {
	puts("no");
	return 0;
    }
	
    long long val = stoll(r);
    long long val2 = stoll(s);

    if (!is_prime(val) || !is_prime(val2)) ok = 0;
	
    if(ok)puts("yes");
    else puts("no");

}
