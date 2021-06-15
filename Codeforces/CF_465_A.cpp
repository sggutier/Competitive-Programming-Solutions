#include <bits/stdc++.h>
using namespace std;
const int limN = 105;

int main() {
    int N ;
    char str[limN];
    int p = 0;
    scanf("%d%s", &N, str);
    for(int bt=1; bt && p<N; p++) {
        bt &= str[p]-'0';
    }
    printf("%d\n", p);
}
