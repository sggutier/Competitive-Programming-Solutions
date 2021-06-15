#include <bits/stdc++.h>
using namespace std;

struct Tree {
	int val;
	Tree *LEFT = NULL, *RIGHT = NULL;
	
	Tree(int x) : val(x) {}
};

Tree * add(Tree *T, int x) {
	if (T == NULL) {
		return new Tree(x);
	}
	
	Tree *t = T; 
		
	while (true) {
		if (x < t->val) {
			if (t->LEFT == NULL) {
				t->LEFT = new Tree(x);
				break;
			}
			t = t->LEFT;
		} else {
			if (t->RIGHT == NULL) {
				t->RIGHT = new Tree(x);
				break;
			}
			t = t->RIGHT;
		}
	}
	
	return T;
}

string str = "";

void dump(Tree * t, bool left = true) {
	if (t == NULL) return;
	
	str += left ? '(' : '[';
	dump(t->LEFT, true);
	dump(t->RIGHT, false);
	str += left ? ')' : ']';
}

string stringify(Tree * t) {
	str = "";
	dump(t);
	return str;
}

int N, K;
Tree * t;
set<string> st;

int main() {
	scanf("%d %d", &N, &K);
	
	
	while(N--) {
		t = NULL;
		for(int i=0,x;i<K;i++) {
			scanf("%d", &x);
			t = add(t, x);
		}
		
		//~ printf("%s\n", stringify(t).c_str());
		st.insert(stringify(t));
	}
	
	printf("%d\n", (int)st.size());
}
