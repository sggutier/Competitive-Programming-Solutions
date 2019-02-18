#include <bits/stdc++.h>
using namespace std;

const long double PI = acos(-1);
const long double eps = 1e-10;

struct Sphere {
	long double x, y, z, r;
	Sphere() {}
	Sphere(int _x, int _y, int _z, int _r) : x(_x), y(_y), z(_z), r(_r) {}
};

long double V = 1e15, sliceSize, x[10005];
int spheres, slices;
Sphere lst[10005];

long double sphereVol(Sphere &s, long double  t) {
	return PI * ((3 * t * s.r * s.r) - (t * t * t) + (2 * s.r * s.r * s.r)) / 3.0;
}

long double getVolume(long double z) {
	long double vol = 1e10 * z;
	
	for(int i=0;i<spheres;i++) {
		Sphere s = lst[i];
		if (s.z - s.r >= z) {
			continue;
		}
		if (s.z + s.r <= z) {
			vol -= (4.0 / 3.0) * PI * s.r * s.r * s.r;
			continue;
		} 
		
		long double partial = z - s.z;
		vol -= sphereVol(s, partial);
				
	}
	
	return vol;
}

long double find(long double lo, long double hi, long double goal) {
	//~ printf("find(%Lf, %Lf, %Lf):\n", lo, hi, goal);
	long double res;
	while(hi - lo > eps) {
		long double mi = (lo + hi) / 2;
		long double curr = getVolume(mi);
		
		//~ printf(" mi: %Lf = %Lf\n", mi, getVolume(mi));
		
		if (curr < goal) {
			lo = mi, res = mi;
		}
		else {
			hi = mi;
		}
	}
	//~ printf("lo: %Lf = %Lf\n", res, getVolume(res));
	return res;
}

int main() {
	cin >> spheres >> slices;
	//~ scanf("%d %d", &spheres, &slices);
	
	for(int i=0;i<spheres;i++) {
		long double x, y, z, r;
		cin >> r >> x >> y >> z;
		//~ scanf("%Lf %Lf %Lf %Lf", &r, &x, &y, &z);
		lst[i] = Sphere(x, y, z, r);		
		V -= (4.0 / 3.0) * PI * r * r * r;
	}
	
	sliceSize = V / slices;
	
	for(int i=1;i<slices;i++) {
		long double goal = sliceSize * i;
		x[i] = find(x[i - 1], 100000, goal);
	}
	x[slices] = 100000;
	
	cout << fixed << setprecision(9);
	
	for(int i=1;i<=slices;i++)
		//~ printf("%.8Lf\n", (x[i] - x[i - 1]) / 1000.0);	
		cout << (x[i] - x[i - 1]) / 1000.0 << endl;


	return 0;
}
