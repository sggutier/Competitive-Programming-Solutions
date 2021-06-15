#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> par;
#define f first
#define s second
typedef long long ll;
const int limN = 1e6 + 5;

int N ;
int ans[limN];

void cicla(int ini, int tam) {
    for(int i=0; i<tam; i++)
        ans[ini + i] = ini + (i+1)%tam;
}

int main() {
    int A, B;
    int pos = 0;

    scanf("%d%d%d", &N, &A, &B);
    for(pos=0; pos<N; pos+=A) {
        if((N-pos) % B) {
            if(N-pos >= A)
                cicla(pos, A);
        }
        else {
            for(; pos<N; pos+=B)
                cicla(pos, B);
            break;
        }
    }

    if(pos > N)
        printf("-1\n");
    else {
        for(int i=0; i<N; i++)
            printf("%d ", ans[i]+1);
        printf("\n");
    }
}
