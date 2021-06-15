#include <bits/stdc++.h>
using namespace std;

double a, b, c, d, p;

double f(double k) {
	return p*(sin(a*k + b) + cos(c*k + d) + 2);
}

int main() {
	int n ;
	cin >> p >> a >> b >> c >> d >> n;
	double ans = 0, mino = 1e50;
	
	for(int i=n; i>=1; i--) {
		double w = f(i);
		mino = min(mino, w);
		ans = max(ans, w - mino);
	}
	
	cout << fixed << setprecision(9) << ans << endl;
}

