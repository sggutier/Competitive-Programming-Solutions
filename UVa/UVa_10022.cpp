#include <bits/stdc++.h>
using namespace std;


int getRn(int n) {
    return ceil(sqrtl(n));
}

int colnA(int n, int rn) {
    rn --;
    return (n-1 - rn*rn) / 2;
}

int colnB(int n, int rn) {
    return (rn * rn - n) / 2 ;
}

int minPth(int a, int b, int rnA, int rnB, int dir) {
    if(rnA == rnB) {
        return abs(a-b);
    }
    int ans = 0;
    if((b - (rnB-1) * (rnB-1)) % 2 == 0) {
        b -= dir;
        ans --;
    }
    while(rnA != rnB) {
        b += dir;
        if(rnB * rnB < b || (rnB-1) * (rnB-1) == b) {
            b -= 2 * dir;
            dir *= -1;
        }
        rnB --;
        ans += 2;
        b -= 2 * rnB;
    }
    return ans + abs(a-b);
}

int calcLev(int n, int rn) {
    return rn * 2 - ((n - (rn-1) * (rn-1)) % 2? 0 : 1);
}

int levDif(int a, int rnA, int b, int rnB) {
    return abs(calcLev(a, rnA) - calcLev(b, rnB));
}

int testCase(int a, int b) {
    if(b < a) swap(a, b);
    int rnA = getRn(a), rnB = getRn(b);
    // return min(minPth(a, b, rnA, rnB, 1), minPth(a, b, rnA, rnB, -1));
    int ans = 0 ;
    if((a - (rnA-1) * (rnA-1)) % 2 == 0) {
        rnA --;
        a -= 2 * rnA;
        ans -- ;
    }
    int x = a, y = a;
    for(int i=rnA; i < rnB; i ++) {
        x += 2 * i -1 ;
        y += 2 * i +1 ;
    }
    if(b < x) {
        ans += x - b;
        b = x;
    }
    else if(y < b) {
        ans += b - y;
        b = y;
    }
    return ans + levDif(a, rnA, b, rnB);
}

int main() {
    int tc;
    bool fst = true;
    for(scanf("%d", &tc); tc; tc--) {
        int a, b;
        scanf("%d%d", &a, &b);
        if(!fst) printf("\n");
        printf("%d\n", testCase(a, b));
        fst = false;
    }
}
