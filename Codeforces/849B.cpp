#include <bits/stdc++.h>
using namespace std;
const int limN = 1005;

int N ;
int nms[limN];

bool fca(int p) {
    bitset <limN> usd;
    int d = __gcd(p, nms[p] - nms[0]);
    for(int i=0; i<N; i++) {
        if(nms[0] + 
    }
}

int main() {
}
