#include <bits/stdc++.h>
using namespace std;
const int limN = 76;

int ways[limN+1];

void precarga() {
    ways[1] = ways[2] = 1;
    for(int i=3; i<=limN; i++) {
        ways[i] = ways[i-2] + ways[i-3];
    }
}

int main() {
    precarga();
    int n;
    while(scanf("%d", &n)!=EOF)
        printf("%d\n", ways[n] + ways[n-1]);
}
