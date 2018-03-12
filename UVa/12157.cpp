#include <bits/stdc++.h>
using namespace std;

void testCase() {
    int N;
    int ans[] = {0, 0};
    for(scanf("%d", &N); N; N--) {
        int tmp;
        scanf("%d", &tmp);
        tmp ++;
        for(int j=0; j<2; j++) {
            ans[j] += (tmp/(30 + 30*j) + (tmp%(30 + 30*j)==0 ? 0 : 1))*(10 + 5*j);
        }
    }
    if(ans[0]<ans[1])
        printf("Mile %d\n", ans[0]);
    else if(ans[0]>ans[1])
        printf("Juice %d\n", ans[1]);
    else
        printf("Mile Juice %d\n", ans[0]);
}

int main() {
    int tc;

    scanf("%d", &tc);
    for(int i=1; i<=tc; i++) {
        printf("Case %d: ", i);
        testCase();
    }
    
    return 0;
}
