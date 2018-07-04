#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct ST {
	ll val = 0, l = 0, r = 0;
	ST *left = NULL, *right = NULL;
	
	ll lazy = 0;
	
	ST(ll L, ll R) {
		l = L, r = R;
		
		if(L == R) 			
			return;
		
		ll M = (L + R) / 2;
		
		left = new ST(L, M);
		right = new ST(M + 1, R);
	}
};

void push(ST *st) {
	if(!st || !st->lazy) return;
	
	st->val += st->lazy * (st->r - st->l + 1);
	
	if(st->left) 
		st->left->lazy += st->lazy;
		
	if(st->right)
		st->right->lazy += st->lazy;
		
	st->lazy = 0;
}

void add(ST *st, ll L, ll R, ll val) {
	if(!st) return;		
	push(st);
	
	if(L > st->r || R < st->l)
		return;
		
	if(L <= st->l && st->r <= R)  {
		st->lazy += val;
		return;
	}
		
	add(st->left, L, R, val);
	add(st->right, L, R, val);
	push(st->left);
	push(st->right);
	
	st->val = 0;
	
	if(st->left) st->val += st->left->val;
	if(st->right) st->val += st->right->val;
}

ll get(ST *st, ll L, ll R) {
	if(!st) return 0;		
	push(st);
	
	if(L > st->r || R < st->l)
		return 0;
		
	if(L <= st->l && st->r <= R)  
		return st->val;
	
	return get(st->left, L, R) + get(st->right, L, R);
}

void pt(ST * st, int lvl = 0) {	
	if(!st) return;
	
	for(int i=0;i<lvl;i++) printf(" ");	
	printf("%lld %lld %lld %lld\n", st->l, st->r, st->val, st->lazy);
	
	pt(st->left, lvl + 1);
	pt(st->right, lvl + 1);
}

ll T, N, C, O, P, Q, V;

int main() {	
	scanf("%lld", &T);
	
	while(T--) {
		scanf("%lld %lld", &N, &C);
		ST* st = new ST(1, N);
		
		//pt(st);
		
		while(C--) {
			scanf("%lld %lld %lld", &O, &P, &Q);
			
			if(Q < P) swap(P, Q);
			
			if(O == 0) {
				scanf("%lld", &V);
				add(st, P, Q, V);
			} else {
				printf("%lld\n", get(st, P, Q));
			}
			
			//pt(st);
		}
	}
}
