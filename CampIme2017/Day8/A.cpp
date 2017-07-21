#include <bits/stdc++.h>
using namespace std;

int a[4], b[4];


int main () {
    for (int i = 0; i < 3; i++) {
	scanf ("%d", a + i);
    }
    for (int i = 0; i < 3; i++)
	scanf ("%d", b + i);

    int x, y;
    x = y = 0;
    
    for (int i = 0; i < 3; i++) {
	if (a[i] > b[i]) x++;
	else if (a[i] < b[i]) y++;
    }
    printf ("%d %d\n", x, y);
}
