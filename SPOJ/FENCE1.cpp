#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);

int main() {
	int n ;
	while(scanf("%d", &n) != EOF && n) {
		double w = n / pi;
		printf("%.2lf\n", w*w*pi / 2);
	}
}

