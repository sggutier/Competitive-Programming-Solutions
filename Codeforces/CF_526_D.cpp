#include <bits/stdc++.h>
using namespace std;
const int LIM_N = 1e6 + 5;

vector <int> funcionZ(const string &S) {
    int lenS = S.length();
    vector <int> z(lenS);
    int x = 0, y = 0 ;
    for(int i = 1 ; i < lenS; i++) {
        z[i] = max(0, min(z[i-x], y-i+1));
        while(i + z[i] < lenS && S[z[i]] == S[i + z[i]]) {
            x = i;
            y = i + z[i];
            z[i] ++;
        }
    }
    return z ;
}

int crg[LIM_N];

int main() {
    cin.sync_with_stdio();
    cin.exceptions(cin.failbit);
    int N ;
    int K ;
    string S ;
    cin >> N >> K ;
    cin >> S ;
    if(K == 1) {
        for(int i=0; i < N; i++)
            printf("1");
        printf("\n");
        return 0 ;
    }
    auto z = funcionZ(S);
    for(long long i=1; i < N; i++) {
        if(z[i]+i < i*K)
            continue;
        crg[i*K - 1] ++;
        long long np = N;
        np = min(np, i*(K+1));
        np = min(np, z[i] + i);
        crg[np] --;
    }
    for(int i=0, c=0; i < N; i++) {
        c += crg[i];
        printf("%d", c? 1 : 0);
    }
    printf("\n");
}
