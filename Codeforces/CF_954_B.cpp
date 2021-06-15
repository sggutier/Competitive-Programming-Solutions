#include <bits/stdc++.h>
using namespace std;

int main() {
    int N ;
    char str[200];
    int ans = (1<<30);

    scanf("%d%s", &N, str);
    ans = N;
    for(int mit=0; mit*2<=N; mit++) {
        bool funca = true;
        for(int i=0; i<mit; i++)
            funca &= str[i] == str[i+mit];
        if(funca)
            ans = min(ans, mit+N-2*mit+1);
    }

    printf("%d\n", ans);
}
