#include <bits/stdc++.h>
using namespace std;

int main() {
    long long minX = 1e9, minY = minX, maxX = -minX, maxY = maxX;
    long long sumA = 0, a, b, c, d;

    int n ;

    cin >> n ;
    for(int i=0; i<n; i++) {
        cin >> a >> b >> c >> d ;
        minX = min(minX, a);
        maxX = max(maxX, c);
        minY = min(minY, b);
        maxY = max(maxY, d);
        sumA += (c-a) * (d-b);
    }

    printf("%s\n", (maxX - minX) * (maxY - minY) == sumA && (maxX - minX) == (maxY - minY)? "YES" : "NO");
}
