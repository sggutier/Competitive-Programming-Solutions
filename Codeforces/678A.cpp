#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    n++;
    printf("%d\n", k*(n/k + (n%k? 1 : 0)));
}
