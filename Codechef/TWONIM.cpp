#include <bits/stdc++.h>
using namespace std;

void testCase() {
	int N ;
	int w = 0;
	scanf("%d", &N);
	for(int i=0, a; i<N; i++) {
		scanf("%d", &a);
		w ^= a;
	}
	cout << w << endl;
	printf("%s\n", w? "Second" : "First");
}

int main() {
	int tc;
	scanf("%d", &tc);
	for(int i=0; i<tc; i++)
		testCase();
}
