#include<bits/stdc++.h>
using namespace std;

const int MAX = 3123;

int n;
int l[MAX];
map<int, int> qtd;
map<int, int> dup;

int main () {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
	scanf("%d", l + i);
	qtd[l[i]]++;
    }
    sort(l, l + n);
    for (int i = 0; i < n; i++) {
	
    }
}
