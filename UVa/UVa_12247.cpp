#include <bits/stdc++.h>
using namespace std;

void testCase(int a, int b, int c, int x, int y) {
    int A[] = {a, b, c};
    int B[] = {x, y, 0};
    int idx[3] = {0, 1, 2};
   
    for(int k=1; k<=52; k++) {
        if(k==a || k==b || k==c || k==x || k==y)
            continue;
        B[2] = k;
        bool works = true;
        do {
            int s = 0;
            for(int i=0; i<3; i++)
                if(A[i] < B[idx[i]])
                    s++;
            if(s < 2) {
                works = false;
                break;
            }
        } while(next_permutation(idx, idx+3)) ;
        if(works) {
            printf("%d\n", k);
            return;
        }
    }
    printf("-1\n");
}

int main() {
    int a, b, c, d, e;
    while(scanf("%d%d%d%d%d", &a, &b, &c, &d, &e)!=EOF && (a || b || c || d || e))
        testCase(a, b, c, d, e);
}
