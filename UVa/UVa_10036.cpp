#include <bits/stdc++.h>
using namespace std;

void testCase() {
    int n, k;

    scanf("%d%d", &n, &k);
    
    bool usdA[k], usdB[k];
    size_t tam = sizeof(usdA);
    memset(usdA, 0, tam);
    usdA[0] = 1;
    bool *a = &usdA[0], *b = &usdB[0];

    
        
    while(n--) {
        memset(b, 0, tam);
        int num ;
        scanf("%d", &num);
        num = (num%k + k)%k;

        // printf("%d => ", num);
        for(int i=0; i<k; i++) {
            if(a[i]) {
                b[(i+num)%k] = true;
                b[(i-num+k)%k] = true;
                // printf(" %d" ,i);
            }
        }
        // printf("\n");
        
        swap(a, b);
    }

    printf("%s\n", a[0]? "Divisible" : "Not divisible");
}

int main() {
    int tc;

    scanf("%d", &tc);
    while(tc--)
        testCase();
    
    return 0;
}
