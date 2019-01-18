#include <bits/stdc++.h>
using namespace std;
const int limN = 1005;

int N ;
int difs[limN];
vector <int> ans;

int main() {
    scanf("%d", &N);
    for(int i=0, a, u=0; i<N; i++) {
        scanf("%d", &a);
        difs[i] = a-u;
        u = a;
    }
    for(int i=1; i<=N; i++) {
        bool fca = true;
        for(int j=i; j<N; j++) {
            if(difs[j] != difs[j%i]) {
                fca = false;
                break;
            }
        }
        if(fca)
            ans.push_back(i);
    }

    printf("%d\n", (int) ans.size());
    for(const int c : ans)
        printf("%d ", c);
    printf("\n");
}
