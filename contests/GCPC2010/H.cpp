#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr, args)

const int MAXN = 512;

typedef double Number;
const Number EPS = 1e-7;

Number mat[MAXN][MAXN];
int idx[MAXN];
int pivot[MAXN];
Number x[MAXN];

bool solve(int nvar, int neq) {
    
    for (int i = 0; i < neq; i++) {
	idx[i] = i;
    }

    int currow = 0;

    vector<int> freeVars;

    for (int col = 0; col < nvar; col++) {
	int pivotrow = -1;
	Number val = 0;

	for (int row = currow; row < neq; row++) {
	    if (fabs(mat[idx[row]][col]) > val + EPS) {
		val = fabs(mat[idx[row]][col]);
		pivotrow = row;		
	    }
	}
	if (pivotrow == -1) { freeVars.push_back(col); continue; }
	swap(idx[currow], idx[pivotrow]);
	pivot[currow] = col;
	for (int c = 0; c <= nvar; c++) {
	    if (c == col) continue;
	    mat[idx[currow]][c] = mat[idx[currow]][c] / mat[idx[currow]][col];	
	}
	mat[idx[currow]][col] = 1;
	for (int row = 0; row < neq; row++) {
	    if (row == currow) continue;
	    Number k = mat[idx[row]][col] / mat[idx[currow]][col];
	    
	    for (int c = 0; c <= nvar; c++)
		mat[idx[row]][c] -= k * mat[idx[currow]][c];
	}
	currow++;
    }



    // Eu codei
    Number V[] = {0, 0, 0, 0};
    int v = 4 - (int)freeVars.size();

    for (int row = 0; row < v; row++) {
	V[row] = mat[idx[row]][nvar];
    }

    

    for (int i = 0; i < neq; i++) {
        Number cur = 1;
	for (int j = 0; j < nvar; j++) {
	    mat[i][j] = cur;
	    cur *= (i + 1);
	}
	mat[i][4] = x[i];
    }

    
    
    for (int row = 0; row < neq; row++) {
	Number val = 0;
	for (int col = 0; col < nvar; col++) val += V[col] * mat[row][col];
	if (val + EPS < mat[row][4] || val - EPS > mat[row][4]) return false;
    }
    return true;
}

int main() {
    int c;
    scanf("%d", &c);
    while(c--) {
	memset(mat, 0, sizeof(mat));
	memset(pivot, 0, sizeof(pivot));
	memset(idx, 0, sizeof(idx));
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
	    double a; 
	    scanf("%lf", &a);
	    x[i] = a;
	}
	for (int i = 0; i < n; i++) {
	    Number cur = 1;
	    for (int j = 0; j < 4; j++) {
		mat[i][j] = cur;
		cur *= (i + 1);
	    }
	    mat[i][4] = x[i];
	}
	
	if (n <= 4 || solve(4, n)) {
	    puts("YES");
	} else {
	    puts("NO");
	}
    }
    return 0;
}
