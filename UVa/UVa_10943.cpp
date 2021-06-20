#include <bits/stdc++.h>
using namespace std;
const int mod = 1e6;

void testCase(int a, int k) {
    vector <int> ways(a+1, 0);
    ways[0] = 1;
    while(k--) {
        for(int i=a; i>0; i--) {
            for(int j=i-1; j>=0; j--) {
                ways[i] = (ways[i] + ways[j])%mod;
            }
        }
    }
    printf("%d\n", ways[a]);
}

int main() {
    int a, b;

    while(scanf("%d%d", &a, &b)!=EOF && (a || b))
        testCase(a, b);
    
    return 0;
}
