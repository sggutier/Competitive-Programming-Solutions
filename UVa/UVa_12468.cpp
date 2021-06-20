#include <bits/stdc++.h>
using namespace std;
const int chanNum = 100;

inline int testCase(int a, int b) {
    return min(abs(a-b), 100-abs(a-b));
}

int main() {
    int a, b;

    while(scanf("%d%d", &a, &b)!=EOF && a!=-1 && b!=-1)
        printf("%d\n", testCase(a,b));
    
    return 0;
}
