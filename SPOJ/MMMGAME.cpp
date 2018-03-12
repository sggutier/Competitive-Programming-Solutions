#include <bits/stdc++.h>
using namespace std;

void testCase() {
    int ans = 0;
    int n ;
    int ucnt = 0;
    scanf("%d", &n);
    for(int i=0, w; i<n; i++) {
        scanf("%d", &w);
        if(w==1)
            ucnt++;
        ans ^= w;
    }
    if(ucnt!=n)
        printf("%s\n", ans? "John" : "Brother");
    else
        printf("%s\n", ucnt%2==0? "John" : "Brother");
}

int main() {
    int tc;
    scanf("%d", &tc);
    for(int i=0; i<tc; i++)
        testCase();
}
