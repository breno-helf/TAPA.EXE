#include <bits/stdc++.h>

using namespace std;

int main() {
    int v[4];
    for (int i = 0; i < 3; ++i) {
	scanf("%d", &v[i]);
    }
    int v2[3];
    for (int i = 0; i < 2; ++i) {
	scanf("%d", &v2[i]);
    }

    sort(v, v+3);
    sort(v2, v2+2);

    int v3[3];
    
    do{
	for (int i = 0; i < 3; ++i) {
	    v3[0] = 2*v[0]+2*v[1];
	    v3[1] = 2*v[1]+v[2];
	}
	sort(v3, v3+2);
	if(v3[0] <= v2[0] && v3[1] <= v2[1]) {
	    puts("Yes");
	    return 0;
	}
    }while(next_permutation(v, v+3));

    sort(v, v+3);
    do{
	for (int i = 0; i < 3; ++i) {
	    v3[0] = 2*v[0]+2*v[1];
	    v3[1] = v[0]+v[1]+v[2];
	}
	sort(v3, v3+2);
 	if(v3[0] <= v2[0] && v3[1] <= v2[1]) {
	    puts("Yes");
	    return 0;
	}
    }while(next_permutation(v, v+3));

    sort(v, v+3);
    do{
	for (int i = 0; i < 3; ++i) {
	    v3[0] = 2*v[0]+v[1];
	    v3[1] = 2*v[2]+v[1]+v[0];
	}
	sort(v3, v3+2);
	if(v3[0] <= v2[0] && v3[1] <= v2[1]) {
	    puts("Yes");
	    return 0;
	}
    }while(next_permutation(v, v+3));

    sort(v, v+3);
    do{
	for (int i = 0; i < 3; ++i) {
	    v3[0] = v[0]+v[1];
	    v3[1] = 3*v[2]+v[1]+v[0];
	}
	sort(v3, v3+2);
 	if(v3[0] <= v2[0] && v3[1] <= v2[1]) {
	    puts("Yes");
	    return 0;
	}
    }while(next_permutation(v, v+3));

    sort(v, v+3);
    do{
	for (int i = 0; i < 3; ++i) {
	    v3[0] = 2*v[0]+v[1]+v[2];
	    v3[1] = v[0]+v[1]+v[2];
	}
	sort(v3, v3+2);
	if(v3[0] <= v2[0] && v3[1] <= v2[1]) {
	    puts("Yes");
	    return 0;
	}
    }while(next_permutation(v, v+3));

    sort(v, v+3);
    do{
	for (int i = 0; i < 3; ++i) {
	    v3[0] = 2*v[0]+v[1]+v[2];
	    v3[1] = 2*v[1]+v[2];
	}
	sort(v3, v3+2);
 	if(v3[0] <= v2[0] && v3[1] <= v2[1]) {
	    puts("Yes");
	    return 0;
	}
    }while(next_permutation(v, v+3));

    sort(v, v+3);
    do{
	for (int i = 0; i < 3; ++i) {
	    v3[0] = 2*v[0]+v[1]+v[2];
	    v3[1] = v[0]+v[1]+v[2];
	}
	sort(v3, v3+2);
 	if(v3[0] <= v2[0] && v3[1] <= v2[1]) {
	    puts("Yes");
	    return 0;
	}
    }while(next_permutation(v, v+3));

    puts("No");

}
