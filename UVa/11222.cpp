#include <bits/stdc++.h>
using namespace std;

void testCase() {
    set <int> reps[10001];
    vector <int> uq[3];
    for(int k=0; k < 3; k++) {
        int l ;
        scanf("%d", &l);
        for(int i=0, a; i < l; i++) {
            scanf("%d", &a);
            reps[a].insert(k);
        }
    }
    for(int i=0; i < 10001; i++)
        if((int) reps[i].size() == 1)
            uq[*reps[i].begin()].push_back(i);
    int maxL  = max(uq[0].size(), max(uq[1].size(), uq[2].size()));
    for(int k=0; k < 3; k++) {
        if((int) uq[k].size() != maxL) continue;
        printf("%d %d", k+1, maxL);
        for(const int a : uq[k])
            printf(" %d", a);
        printf("\n");
    }
}

int main() {
    int tc ;
    scanf("%d", &tc);
    for(int i=1; i <= tc; i++) {
        printf("Case #%d:\n", i);
        testCase();
    }
}
