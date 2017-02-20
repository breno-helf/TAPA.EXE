#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

const int N = 50;


typedef long long ll;

ll mp[(1<<21)];
ll mp2[(1<<21)];

int sum[(1<<21)];
int sum2[(1<<21)];

map<ll,int> st;

ll val(string a){
    int n = a.size();
    ll ans = 0;
    char init = a[0];
    int i = 0;
    while(i < n && a[i] == init){
	if(a[i]=='W')ans += (1LL<<40);
	else ans -= (1LL<<40);
	i++;
    }
    int cnt = 1;
    for(; i<n; i++){
	if(a[i]=='W')ans += (1LL<<(40-cnt));
	else ans -= (1LL<<(40-cnt));
	cnt++;
    }

    return ans;
}

vector <ll> v;
vector <ll> v2;

ll qtd[N];
int tam[N];

int main(){
	
    int n;
    cin >> n;
    string a;
    for(int i = 0; i < n; i++){
	cin >> a;
	qtd[i] = val(a);
	tam[i] = a.size();
    }

    for(int i = 0; i < n/2; i++){
	v.push_back(qtd[i]);
    }

    for(int i = n/2; i < n; i++){
	v2.push_back(qtd[i]);
    }	

    int resp = 0;

    mp[0]=0;
    for(int i = 0; i < (1LL<<v.size()); i++){
	for(int j = 0; j < v.size(); j++){
	    if((i&(1LL<<j))==0){
		mp[i|(1LL<<j)]=mp[i]+v[j];
		sum[i|(1LL<<j)]=max(sum[i|(1LL<<j)],sum[i]+tam[j]);
	    }
	}
	if(st.find(mp[i])==st.end())st[mp[i]]=sum[i];
	else st[mp[i]]= max(st[mp[i]],sum[i]);
    }
    mp2[0]=0;
    for(int i = 0; i < (1LL<<v2.size()); i++){
	for(int j = 0; j < v2.size(); j++){
	    if((i&(1LL<<j))==0){
		mp2[i|(1LL<<j)]=mp2[i]+v2[j];
		sum2[i|(1LL<<j)]=max(sum2[i|(1LL<<j)],sum2[i]+tam[v.size()+j]);
	    }
	}
	if(st.find(-mp2[i])!=st.end())resp=max(resp,sum2[i]+st[-mp2[i]]);
    }
    printf("%d\n",resp);

}
