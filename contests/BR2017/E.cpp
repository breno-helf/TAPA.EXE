#include <bits/stdc++.h>
using namespace std;

const int N = 1100;

string dp[N];


int n;


int fpow(int a, int b){
  int c = 1;
  for(;b; b>>=1 , a = a * 1ll * a % n){
    if(b&1) c = c * 1ll * a % n;
  }
  return c;
}

int calc(string b){
  
  int pot = 1;
  int val = 0;
  for(int i = b.size()-1; i >= 0; i--){
    val = (val + pot * 1ll * (b[i]-'0')) % n;
    pot = pot * 1ll * 10 % n;
  }
  return val;
}


int main(){
  string a;
  string b;
  cin >> a >> n;
  b = a;
  if(a[0] == '?'){
    b[0] = '1';
  }
  for(int i = 1; i < a.size(); i++) {
    if(a[i] == '?'){
      b[i] = '0';
    }
  }

  dp[calc(b)] = b;
  
  for(int i = a.size()-1; i>= 1; i--) {
    if(a[i] == '?'){
      for (int j = 0; j < n; j++) {
	if(dp[j] != ""){
	  for (int k = 0; k < 10; k++) {
	    int at = (k-dp[j][i]+'0'+n)%n;
	    at = (at * 1ll *  fpow(10, (int)a.size()-i-1)) % n;
	    if( dp[(j+at)%n] == ""){
	      string sp = dp[j];
	      sp[i] = k + '0';

	      dp[(j+at)%n] = sp;
	    }
	  }
	}
      }
    }
  }
  int i = 0;
  if(a[i] == '?'){
    for (int j = 0; j < n; j++) {
      if(dp[j] != ""){
	for (int k = 1; k < 10; k++) {
	  int at = (k-dp[j][i]+'0'+n)%n;
	  at = at * 1ll * fpow(10, (int)a.size()-i-1) % n;
	  if(dp[(j+at)%n] == ""){
	    string sp = dp[j];
	    sp[i] = k + '0';
	    dp[(j+at)%n] = sp;
	  }
	}
      }
    }
  }
  int ok = 1;
  for(int i = 0; i < dp[0].size(); i++){
    if(dp[0][i] != '0') ok = 0;
  }
  if(dp[0] == "" || ok){
    printf("*\n");
  }
  else{
    printf("%s\n",dp[0].c_str());
  }
  

}
 
