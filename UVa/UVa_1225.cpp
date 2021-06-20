#include <bits/stdc++.h>
using namespace std;

void testCase(int n) {
    vector <int> cnt(10, 0);
    for(int i=1; i<=n; i++) {
        int cpy = i;
        while(cpy) {
            cnt[cpy%10]++;
            cpy/=10;
        }
    }
    for(int i=0; i<10; i++) {
        if(i)
            printf(" ");
        printf("%d", cnt[i]);
    }
    printf("\n");
}

int main() {
    int n;
    int tc;

    for(scanf("%d", &tc); tc; tc--) {
        scanf("%d", &n);
        testCase(n);
    }
    
    return 0;
}
