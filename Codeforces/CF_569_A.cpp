#include <bits/stdc++.h>
using namespace std;

int main() {
    long long T, S, q;
    int ans = 0;
    
    cin >> T >> S >> q;
    do {
        ans ++;
        S += (q-1)*S;
    } while(S < T);

    printf("%d\n", ans);
}
