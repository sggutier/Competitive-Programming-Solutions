#include <bits/stdc++.h>
using namespace std;

int N, X;
double ANS;

int main() {
    scanf("%d", &N);

    while(N--) {
        scanf("%d", &X);
        if(!X)  ANS += 2.0;
        else    ANS += (1.0 / X);
    }
    printf("%.7lf\n", ANS);
    return 0;
}
