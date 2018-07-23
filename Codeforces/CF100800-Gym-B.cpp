#include <bits/stdc++.h>
using namespace std;
typedef double ld;

const ld PI = M_PI;

int N, D[4], T[4];
double g;

ld to_rad(ld angle) { return (angle/ 180) * PI ; }
ld vel_sqr(ld v0, ld s, ld theta) { 
	return v0 + 2 * g *  s * cos(theta); 
}

int main() {
	cin >> N >> g;
	
	for(int i=0;i<N;i++) 
		cin >> D[i] >> T[i];
		
	cout << fixed;
	cout << setprecision(9);
	for(int i=0;i<N;i++) {
		ld v0 = 0.0;
		
		//~ printf("---- from %d\n", i);
		
		for(int j=i;j<N;j++) {
			v0 = vel_sqr(v0, D[j], to_rad(T[j]));
			//~ printf("%.8f %.8f\n", v0, sqrt(v0));
		}
		
		cout << sqrt(v0)   << endl;
	}

	return 0;
}
 
