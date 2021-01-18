#include <bits/stdc++.h>
using namespace std;
const int LIM_N = 2000;
const int LIM_K = 1e6 ;

int main() {
    int N ;
    int s = 0, k = 0;
    scanf("%d", &N);

    vector <int> ans ;

    ans.push_back(-1);
    while(s - k - 1 < N) {
        k ++ ;
        int d = min(N+k+1-s, LIM_K);
        ans.push_back(d);
        s += d ;
    }

    printf("%d\n", (int) ans.size());
    for(const int a : ans)
        printf("%d ", a);
    printf("\n");
}
