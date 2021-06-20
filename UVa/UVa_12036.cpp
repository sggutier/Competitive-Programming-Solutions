#include <bits/stdc++.h>
using namespace std;

bool testCase() {
    int N ;
    vector <int> reps(201);
    bool ans = true;

    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            int a;
            scanf("%d", &a);
            a += 100;
            if(reps[a]++>=N)
                ans = false;
        }
    }

    return ans;
}

int main() {
    int tc;
    scanf("%d", &tc);
    for(int i=1; i<=tc; i++) {
        printf("Case %d: %s\n", i, testCase()? "yes" : "no" );
    }
}
