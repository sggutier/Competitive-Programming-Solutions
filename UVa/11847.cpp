#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    double log2 = log(2);
    while(scanf("%d", &n)!=EOF && n) {
        printf("%d\n", (int) (log(n) / log2));
    }
}
