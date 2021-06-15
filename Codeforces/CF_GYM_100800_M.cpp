#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll M, N, T[1005], X[1005];
set<double> V, D;

int main() {
	scanf("%lld %lld", &M ,&N);
	
	for(int i=0;i<M;i++) 
		scanf("%lld", &T[i]);
		
	for(int i=0;i<N;i++) 
		scanf("%lld", &X[i]);
	
	N--, M--;
	
	for(int i=0;i<M;i++) 
		T[i] = T[i+1] - T[i];
		
	for(int i=0;i<N;i++)
		X[i] = X[i+1] - X[i];
	
	for(int i=0;i+M-1<N;i++) {
		bool w = true;
		double k = (double)X[i] / T[0];
		
		for(int j=0;j<M;j++) {
			if((double)X[i+j] / T[j] != k) {
				w = false;
				break;
			}				
		}
		
		if(w) {
			V.insert(k);
			D.insert(X[i]);
		}		
	}
	
	vector<double> D2;
	
	for(auto d : D)
		D2.push_back(d);
	
	printf("%d\n", (int)V.size());

	for(int i=0;i<(int)D2.size();i++)
		printf("%.0f%s", D2[i], i < (int)D2.size() - 1 ? " " : "\n");
}
