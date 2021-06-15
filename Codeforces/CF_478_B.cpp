#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a, b, c, d;
    long long minF, maxF;
    cin >> a >> b ;
    a = a-b;
    maxF = (a*(a+1))/2;
    d = a/b;
    c = a%b;
    minF = b * ((d*(d+1))/2);
    minF += c * (d+1);
    cout << minF << " " << maxF << endl;
}
