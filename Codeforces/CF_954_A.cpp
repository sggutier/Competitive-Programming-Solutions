#include <bits/stdc++.h>
using namespace std;

int main() {
    int N ;
    char str[200];
    int ans = 0;

    scanf("%d%s", &N, str);
    for(int i=0; i<N; i++) {
        ans++;
        if(i+1 < N && str[i]!=str[i+1])
            i++;
    }

    printf("%d\n", ans);
}
