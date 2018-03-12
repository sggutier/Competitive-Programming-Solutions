#include <bits/stdc++.h>
using namespace std;

void testCase(int g1, int g2) {
    int gears1[g1], gears2[g2];
    int G=0;
    double ratios[g1*g2];

    for(int i=0; i<g1; i++) {
        scanf("%d", &gears1[i]);
    }
    for(int i=0; i<g2; i++) {
        scanf("%d", &gears2[i]);
    }

    for(int i=0; i<g1; i++) {
        for(int j=0; j<g2; j++) {
            ratios[G++] = (1.0*gears1[i])/gears2[j];
        }
    }

    sort(ratios, ratios+G);

    double ans = 0.0;
    for(int i=1; i<G; i++)
        ans = max(ans, ratios[i]/ratios[i-1]);

    printf("%.2f\n", ans);
}

int main() {
    int g1, g2;

    while(scanf("%d", &g1)!=EOF && g1!=0) {
        scanf("%d", &g2);
        testCase(g1, g2);
    }
    
    return 0;
}
