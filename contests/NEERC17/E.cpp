#include <bits/stdc++.h>
using namespace std;

const int MAX = 1123;

int n, a[MAX];
int pot[MAX];

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
	scanf("%d", a + i);
    }

    bool ok = true;
    vector<int> unicorn;
    
    for (int i = 0; i < n; i++) {
	if (a[i] >= 0) {
	    pot[a[i]]++;
	} else {
	    if (pot[-a[i]] > 0) pot[-a[i]]--;
	    else if (pot[0] > 0) {
		pot[0]--;
		unicorn.push_back(-a[i]);
	    } else {
		ok = false;
		break;
	    }
	}
    }

    if (ok) {
	puts("Yes");

	while (pot[0] > 0) {
	    pot[0]--;
	    unicorn.push_back(1);
	}
	
	for (int k : unicorn) {
	    printf("%d ", k);
	}
	printf("\n");
    } else puts("No");
}
