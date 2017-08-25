#include <bits/stdc++.h>

using namespace std;

int pot10[10];

int main(){
	int t;
	cin >> t;
	string s;
	pot10[0] = 1;
	for(int i = 1; i <= 9; i++){
		
	}
	for(int cas = 0; cas < t; cas++){
		cin >> s;
		while(s.size()>0 && s.back()=='0'){
				s.pop_back();
		} 
		int vat = 0, vnxt = 0;
		if(s.back()=='5'){
			vat = 2*s.size()-1;
		}
		else {
			vat = 2*s.size();	
		}
		int at = stoi(s);
		//cout << s << endl;
		int l = ceil(0.95 * at);
		int r = floor(1.05 * at);
		int ok = 1;
		for(int i = at-100; i <= at+100; i++){
			if(l <= i && i <= r){
				string test = to_string(i);
				while(test.size()>0 && test.back()=='0'){
					test.pop_back();
				}
				if(test.back()==5){
					vnxt = 2*test.size()-1;
				}
				else{
					vnxt = 2*test.size();
				}
				if(vnxt<vat){
					ok = 0;	
				}
			}

		}
		if(!ok)puts("absurd");
		else puts("not absurd");
		
	}
}
