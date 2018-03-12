#include <bits/stdc++.h>
using namespace std;

void testCase() {
    int N ;
    int ans = 0;

    scanf("%d", &N);
    for(int i=1; i<=N; i++) {
        int w ;
        scanf("%d", &w);
        if(w%2)
            ans ^= i;
    }

    printf("%s Wins\n", ans? "Tom" : "Hanks");
}

int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--)
        testCase();
}
