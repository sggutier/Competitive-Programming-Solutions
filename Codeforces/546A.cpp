#include <bits/stdc++.h>
using namespace std;

int main() {
    long long k, n, w;
    cin >> k >> n >> w ;
    cout << max(0LL, k*((w*(w+1))/2) - n) << endl;
}
