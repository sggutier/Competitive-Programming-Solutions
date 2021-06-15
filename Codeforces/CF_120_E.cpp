#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tc;
    scanf("%d", &tc);
    for(int i=0, b; i<tc; i++) {
        scanf("%d", &b);
        printf("%d\n", 1-b%2);
    }
}
