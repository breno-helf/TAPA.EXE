#include <bits/stdc++.h>
using namespace std;

int N, L, R;
struct Treap{
	int prior, size;
	char val;
	bool rev;
	Treap *left, *right;
	Treap(){}
	Treap(char v) {
		prior = rand();
		size = 1;
		val = v;
		rev = false;
		left = right = NULL;
	}
};

inline int size(Treap* t){
	return (t ? t->size : 0);
}

inline void push(Treap* t){
	if (t->rev) {
		if (t->left) {
			swap(t->left->left, t->left->right);
			t->left->rev ^= 1;
		}
		if(t->right) {
			swap(t->right->left, t->right->right);
			t->right->rev ^= 1;
		}
	}
	t->rev = false;
}

inline void pull(Treap* t){
	t->size = 1 + size(t->left) + size(t->right);
}

int NN = 0;
Treap pool[200000];

inline Treap* new_treap(char val){
	pool[NN] = Treap(val);
	return &pool[NN++];

}

Treap* merge(Treap* a, Treap* b){
	if(!a || !b) return (a ? a : b);
	if(a->prior > b->prior){
		push(a);
		a->right = merge(a->right, b);
		pull(a);
		return a;
	}
	else{
		push(b);
		b->left = merge(a, b->left);
		pull(b);
		return b;
	}
}

void split(Treap* t, Treap*& a, Treap*& b, int k){
	if(!t) { a = b = NULL; return;}
	push(t);
	if(size(t->left) < k){
		a = t;
		split(t->right, a->right, b, k - size(t->left) -1);
		pull(a);
	}
	else {
		b = t;
		split(t->left, a, b->left, k);
		pull(b);
	}
}

void reverse(Treap*& t){
	Treap *a, *b, *c, *d;
	split(t, a,  b, R);
	split(a, c, d, L-1);
	swap(d->left, d->right);
	d->rev ^= 1;
	t = merge(merge(c,d),b);
}

void findleft(Treap*& t){
	Treap *a, *b, *c, *d;
	split(t, a,  b, L);
	split(a, c, d, L-1);
	printf("%c",d->val);
	t = merge(merge(c,d),b);
}
void findright(Treap*& t){
	Treap *a, *b, *c, *d;
	split(t, a,  b, R);
	split(a, c, d, R-1);
	printf("%c",d->val);
	t = merge(merge(c,d),b);
}


Treap* root = NULL;

int main(){

	scanf("%d %d %d", &N, &L , &R);
	for(int i = 0; i < N; i++){
			char x;
			scanf(" %c", &x);
			root = merge(root, new_treap(x));
	}
	int Q;
	scanf("%d", &Q);
	for(int i = 0; i < Q; i++){
		char a;
		scanf(" %c", &a);
		if(a == 'Q'){
			char b;
			scanf(" %c", &b);
			if(b == 'L') findleft(root);
			else findright(root);
		}
		else if(a == 'R')reverse(root);
		else{
			char b, c;
			scanf(" %c %c", &b, &c);
			if(b=='L'){
				if(c=='R')L++;
				else L--;
			}
			else{
				if(c=='R') R++;
				else R--;	
			}
		}
	}
	
}
