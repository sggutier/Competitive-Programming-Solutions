#include <bits/stdc++.h>
using namespace std;

void testCase() {
    int n;
    bool valid = true;

    scanf("%d", &n);
    for(int i=0, lst; i<n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        if(!i)
            lst = a-b;
        valid &= (a-b == lst);
        lst = a-b;
    }

    printf("%s\n", valid? "yes" : "no");
}

int main() {
    int tc;

    scanf("%d", &tc);
    for(int i=0; i<tc; i++) {
        if(i)
            printf("\n");
        testCase();
    }
    
    return 0;
}
