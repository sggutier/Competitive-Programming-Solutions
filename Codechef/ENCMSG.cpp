#include <bits/stdc++.h>
using namespace std;
const int limN = 1005;

int main() {
    char str[limN];
    int T;
    for(scanf("%d", &T); T; T--) {
        int N ;
        scanf("%d", &N);
        scanf("%s", str);
        for(int i=1; i<N; i+=2)
            swap(str[i], str[i-1]);
        for(int i=0; i<N; i++)
            printf("%c", 'z'-str[i]+'a');
        printf("\n");
    }
}
