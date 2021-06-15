#include <bits/stdc++.h>
using namespace std;
const int limN = 1005;

int N ;
double poss[limN];
double ans[limN];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	//~ scanf("%d", &N);
	cin >> N ;
	for(int i=0; i<N; i++)
		cin >> poss[i];
		//~ scanf("%d", &poss[i]);
	
	tuple <double, int, int> truAns = {1e9, 0, 0};
		
	for(int l=0; l<N; l++) {
		for(int r=l+1; r<N; r++) {
			double tot = 0;
			double sep = (poss[r] - poss[l]) / ( (double) r-l);
			double p = poss[0];
			
			for(int i=0; i<N; i++) {
				if(i==l || i==r) continue;
				p = poss[l] + (i-l) * sep;
				tot += fabs(poss[i] - p);
			}
			
			truAns = min(truAns, {tot, l, r});
		}
	}
	
	double tot ;
	int l, r;
	if(true) {
		tie(tot, l, r) = truAns;
		ans[l] = poss[l];
		ans[r] = poss[r];
		double sep = (poss[r] - poss[l]) / (r-l);
		double p = poss[0];
		
		for(int i=0; i<N; i++) {
			if(i==l || i==r) continue;
			p = poss[l] + (i-l) * sep;
			ans[i] = p;
		}
	}
	
	cout << fixed << setprecision(4) << tot << endl;
	for(int i=0; i<N; i++)
		cout << fixed << setprecision(7) << ans[i] << " ";
	cout << endl;
	
	fclose(stdin);
	fclose(stdout);
}

