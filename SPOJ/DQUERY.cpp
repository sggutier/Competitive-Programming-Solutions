#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
typedef pair <int, int> pii;
typedef pair <pii, int> piii;

template <class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag,
tree_order_statistics_node_update>;

int N, V[30005], Q, A, B, ANS[200005], LST[1000006];
Tree <int> arbo;
piii L[200005];

int main() {
	scanf("%d", &N);
	
	for(int i=1;i<=N;i++) 
		scanf("%d", &V[i]);
	
	scanf("%d", &Q);
	
	for(int i=0;i<Q;i++) {
		scanf("%d %d", &A, &B);		
		L[i] = { { B, A }, i };
	}
	
	sort(L, L + Q);
	
	int idx = 0;
	
	for(int i=1;i<=N;i++) {
		if(LST[V[i]]) arbo.erase(LST[V[i]]);
		arbo.insert(i);
		LST[V[i]] = i;
		
		while(L[idx].first.first == i) {
			A = L[idx].first.second;
			int odx = L[idx].second;
			
			ANS[odx] = arbo.size() - arbo.order_of_key(A);
			idx++;			
		}			
	}
	
	for(int i=0;i<Q;i++)
		printf("%d\n", ANS[i]);
	
}
