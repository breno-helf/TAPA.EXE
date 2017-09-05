#include<bits/stdc++.h>
using namespace std;

const int MAX = 1123;

typedef pair<int, int> pii;

struct node {
    int val;
    int l, r;
    int ed;

    node(int V = -1, int L = 0, int R = 0, int E = 0):
	val(V), l(L), r(R), ed(E) {}
};

node T[2][MAX];
int u[2];
int N1, N2;
int mrk[MAX][MAX];
char s[MAX];
queue<pii> Q;

void add(int x) {
    int tam = strlen(s);
    int cur = 0;	
    for (int i = 0; i < tam; i++) {
	if (s[i] == '0') {
	    if (!T[x][cur].l) {		
		node A = node(0, 0, 0, 0);
		T[x][u[x]] = A;
		T[x][cur].l = u[x]++;
	    }
	    cur = T[x][cur].l;
	} else {
	    if (!T[x][cur].r) {		
		node A = node(1, 0, 0, 0);
		T[x][u[x]] = A;
		T[x][cur].r = u[x]++;
	    }
	    cur = T[x][cur].r;
	}
    }    
    T[x][cur].ed = 1;
}

void pusha(int a, int b) {
    if (T[0][a].l && T[1][b].l) {
	int A = T[0][a].l;
	int B = T[1][b].l;
	if (!mrk[A][B]) {
	    Q.push(pii(A, B));
	    mrk[A][B] = 1;
	    //printf("        add %d %d\n", A, B);
	}

	if (T[0][A].ed && !mrk[0][B]) {
	    Q.push(pii(0, B));
	    mrk[0][B] = 1;
	    //printf("        add %d %d\n", 0, B);
	}
	
	if (T[1][B].ed && !mrk[A][0]) {
	    Q.push(pii(A, 0));
	    mrk[A][0] = 1;
	    //printf("        add %d %d\n", A, 0);
	}
		
	if (T[0][A].ed && T[1][B].ed && !mrk[0][0]) {
	    Q.push(pii(0, 0));
	    mrk[0][0] = 1;
	    //printf("        add %d %d\n", 0, 0);
	}		
    }

    if (T[0][a].r && T[1][b].r) {
	int A = T[0][a].r;
	int B = T[1][b].r;
	if (!mrk[A][B]) {
	    Q.push(pii(A, B));
	    mrk[A][B] = 1;
	    //printf("        add2 %d %d\n", A, B);
	}

	if (T[0][A].ed && !mrk[0][B]) {
	    Q.push(pii(0, B));
	    mrk[0][B] = 1;
	    //printf("        add2 %d %d\n", 0, B);
	}
		
	if (T[1][B].ed && !mrk[A][0]) {
	    Q.push(pii(A, 0));
	    mrk[A][0] = 1;
	    //printf("        add2 %d %d\n", A, 0);
	}
		
	if (T[0][A].ed && T[1][B].ed && !mrk[0][0]) {
	    Q.push(pii(0, 0));
	    mrk[0][0] = 1;
	    //printf("        add2 %d %d\n", 0, 0);
	}		
    }
	    
}

int main() {
    while(scanf("%d%d", &N1, &N2) != EOF) {
	memset(T, 0, sizeof(T));
	memset(mrk, 0, sizeof(mrk));
	u[0] = u[1] = 1;
	T[0][0].val = T[1][0].val = -1;
	
	for (int i = 0; i < N1; i++) {
	    scanf(" %s", s);
	    add(0);
	}

	for (int i = 0; i < N2; i++) {
	    scanf(" %s", s);
	    add(1);
	}

	while(!Q.empty()) Q.pop();

	pusha(0, 0);

	while (!Q.empty()) {
	    pii v = Q.front();
	    int a = v.first;
	    int b = v.second;
	    Q.pop();

	    //printf("--> No estado %d %d\n", a, b);
	    
	    if (a == 0 && b == 0) break;

	    pusha(a, b);
	}

	if (mrk[0][0]) puts("S");
	else puts("N");
    }    
}
