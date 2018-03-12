#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, k ;
    cin >> n >> k ;
    n -= k;
    cout << ((n/k)%2==0? "YES" : "NO") << endl;
}
