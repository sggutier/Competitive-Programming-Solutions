#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;

int main() {
    int N;
    int arr[limN];
    int mino=1e9 + 5, ans = limN;

    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%d", &arr[i]);
        mino = min(mino, arr[i]);
    }

    for(int i=0, up=-1; i<N; i++) {
        if(arr[i]!=mino)
            continue;
        if(up!=-1)            
            ans = min(ans, i-up);
        up = i;
    }

    printf("%d\n", ans);
}
