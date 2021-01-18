#include <bits/stdc++.h>
using namespace std;
const int LIM_N = 3005;

int main() {
    char tmp[20];
    int N ;
    pair <int, string> ppl[LIM_N];
    int ans[LIM_N];
    scanf("%d", &N);
    for(int i=0; i < N; i++) {
        scanf("%s%d", tmp, &ppl[i].first);
        ppl[i].second = tmp;
    }

    sort(ppl, ppl+N);
    for(int i=0, prevV = -1; i < N; i++) {
        if(ppl[i].first > i) {
            printf("-1\n");
            return 0 ;
        }
        int x = ppl[i].first;
        ans[i] = 1 ;
        if(prevV == x) continue;

        int df = x - prevV;
        for(int j=i-1; j >= 0; j--) {
            if(ans[j] > 1)
                ans[j] ++ ;
        }
        for(int j=i-1; df && j >= 0; j--) {
            if(ans[j] == 1) {
                ans[j] ++;
                df --;
            }
        }
        prevV = x;
    }

    for(int i=0; i < N; i++)
        printf("%s %d\n", ppl[i].second.c_str(), ans[i]);
}
