#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K, t;
    cin >> N >> K >> t ;
    int ini = max(0, t-K), fin = min(N, t);
    printf("%d\n", fin-ini);
}
