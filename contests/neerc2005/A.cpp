#include <bits/stdc++.h>

using namespace std;


multiset <int> st; 

int main(){
    string s;
    int k, k2;
    cin >> s >> k;
    k2 = k;
    int n = s.size();
    int at = 0;
    int at2 = 0;
    for(int i = 0; i < n; i++) s+='0';
    n = s.size();
    string ans = "";
    while(at<n){
	while(st.size()<k2+1){
	    st.insert(s[at]-'0');
	    at++;
	}
	int val = *st.rbegin();
	ans+=(char)val+'0';
	if(ans.size()>=n/2-k)break;
	while(s[at2]-'0'!=val){
	    st.erase(st.find(s[at2]-'0'));
	    k2--;
	    at2++;
	}
	st.erase(st.find(s[at2]-'0'));
	at2++;
    }
    cout << ans  << endl;

}    
