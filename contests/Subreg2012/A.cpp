#include<bits/stdc++.h>

const int MAX = 1123;

int n, l, c;
int sz[MAX];
char s[112];

int main() {
    while (scanf("%d%d%d", &n, &l, &c) != EOF) {
	int resp = 0;
	int L = 0, C = 0;
	for (int i = 0; i < n; i++) {
	    scanf(" %s", s);
	    sz[i] = strlen(s);
	}
	//printf("\n");
	for (int i = 0; i < n; i++) {
	    //printf("%d %d\n", C, L);
	    if (C == 0) {
		C += sz[i];		
	    } else {
		if (C + sz[i] + 1 > c) {
		    L++;
		    C = sz[i];
		} else C += sz[i] + 1;		
	    }

	    if (L >= l) {
		L = 0;
		resp++;
	    }
	}

	printf("%d\n", resp + (C != 0 || L != 0));
    }
    return 0;
}
