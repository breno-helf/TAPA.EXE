#include <bits/stdc++.h>

using namespace std;


int main(){
  int x[3], y[3];
  for(int i = 0; i < 3; i++){
    scanf("%d", &x[i]);
  }
  for(int i = 0; i < 3; i++){
    scanf("%d", &y[i]);
  }
  int val = 0;
  for(int i = 0; i < 3; i++){
    val += max(0, y[i]-x[i]);
  }
  printf("%d\n",val);
  
}
