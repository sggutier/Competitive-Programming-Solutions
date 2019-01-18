#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int N, K, X;
vi adj[205][205];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &N);
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &X);			
			if (X) adj[i][X].push_back(j);
		}
	}
	
	set<int> A, B;
	A.insert(1);
	
	scanf("%d", &K);
	for(int i = 0 ; i < K; i++) {
		scanf("%d", &X);
		B.clear();
		for (int u : A) for (int v : adj[u][X]) B.insert(v);
		A = B;
	}
	
	printf("%d\n", (int)A.size());
	for (int u : A) printf("%d ", u);
	printf("\n");
}
