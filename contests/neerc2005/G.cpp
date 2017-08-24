#include<bits/stdc++.h>
using namespace std;

int main() {
    char c;
    stack<int> st;
    while((c = getchar()) != EOF) {
	if (c == '<') {
	    string cur = "";
	    cur += c;
	    while((c = getchar()) != '>') cur += c;
	    cur += c;
	    if (cur == "<UP>") {
		st.push(0);
	    } else if (cur == "<DOWN>") {
		st.push(1);
	    } else {
		st.pop();
	    }
	    //cout << cur << '\n';
	} else {
	    if (st.empty()) printf("%c", c);
	    //else printf("%d \n", st.empty());
	    else if (st.top() == 0) printf("%c", toupper(c));
	    else printf("%c", tolower(c));
	}	
    }
    //printf("\n");
}
